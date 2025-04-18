# Conquering C++20 Ranges

C++ Conference 2021  
[YouTube Link](https://youtu.be/3MBtLeyJKg0)


## Definition of `std::ranges::range` and `view` concepts

```cpp
template <class T>
concept range = requires (T t) {
    std::ranges::begin(t);
    std::ranges::end(t);
};

template <class T>
concept view = std::ranges::range<T>
    && std::movable<T>
    && std::ranges::enable_view<T>;
```

## Fibonacci Function Example

Given positive integers `n` and `k`, print the first `n` elements of the Fibonacci sequence which are also exactly divisible by `k`.  
For example, for `n=5` and `k=3`, the output should be `[ 0, 3, 21, 144, 97 ]`.

```C++
void fib_fun(int n, int k) {
    int found = 0;
    std::size_t cur = 0;
    std::size_t next = 1;

    while (found < n) {
        if (cur % k == 0) {
            ++found;
            std::cout << cur << "\n";
        }
        cur = std::exchange(next, cur + next);
    }
}

/* Define an iterator-alike sequence generator. */
struct fib_generator {
public:

    using value_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    const std::size_t operator*() const { return _cur; }

    fib_generator& operator++() {
        _cur = std::exchange(_next, _cur + _next);
        return *this;
    }

    fib_generator operator++(int) { 
        auto temp = *this;
        ++*this; 
        return temp;
    }

    bool operator==(const fib_generator&) const = default;

private:
    std::size_t _cur = 0;
    std::size_t _next = 1;
};
```

### Using `std::ranges` and `std::subrange`

```C++
namespace rng = std::range;

namespace views {
    /* Specify the range is endless */
    constexpr auto fibonacci = 
        rng::subrange<fib_iterator, rng::unreachable_sentinel_t>{};
}

/* Update the Fibonacci function with created views */
void fibfun(int n, int k) {
    auto view = views::fibonacci
        | std::views::filter([k](auto i) { return i % k == 0; })
        | std::views::take(n);

    rng::copy(view, std::ostream_iterator<std::size_t>(std::cout, ","));
}
```

## String Trimming Problem

```C++
template<std::range::view V, typename Pred>
    requires std::range::bidirectional_range<V>
        && std::indirect_unary_predicate<Pred, std::range::iterator_t<V>>
class drop_last_while_view
    : public std::range::view_interface<drop_last_while_view<V, Pred>> {

private:
    V _base;
    Pred _pred;
    std::optional<std::range::iterator<V>> _cached_end;

public:
    drop_last_while_view() = default;

    drop_last_while_view(V base, Pred pred)
        : _base(std::move(base),
          _pred(std::move(pred)
    {}

    auto begin() {
        return std::range::begin(_base);
    }

    auto end() {
        return std::range::find_if_not(std::range::rbegin(_base), std::range::rend(_base), _pred).base();
    }
};

namespace views {
    /* Create a factory function to accommodate the template class */
    struct drop_last_while_fn {
        template<std::ranges::viewable_range R, typename R>
        constexpr auto operator()(R&& r, Pred pred) const
            -> drop_last_while_view<std::views::all_t<R>, Pred>
        {
            return drop_last_while_view<std::views::all_t<R>, Pred>(
                std::views::all(std::forward<R>(r)), std::move(pred)
            );
        }
    }
}

inline constexpr auto drop_last_while = drop_last_while_fn{};
```

## Ranges in Practice

**Problem statement:** given an array of integers, calculate the sum of squares of the values it contains.  
Example input: `[ -2, -1, 0, 1, 2 ]`; example output: `10`

```C++
/* Solution 1 with std::transform */
std::vector<int> vec = get_src_data();
// transform the vector in place
std::transform(vec.begin(), vec.end(), // specify a range
    vec.begin(),                       // put it back at this iterator
    [](int i) { return i * i; }        // lambda requirement
);
// equivalent to the following:
// ranges::transform(vec, vec.begin(),
//     [](int i) {return i * i; });
auto sum_sq = std::accumulate(vec.begin(), vec.end(), 0);

/* --------------------------------------- */
/* Solution 2 with 'lazy' views::transform */
/* --------------------------------------- */
auto view = views::transform(vec,
    [](int i) { return i * i; });
auto sum_sq = std::accumulate(view.begin(), view.end(), 0);
/* Using views With pipeline syntax */
auto view = vec
    | views::transform([](int i) { return i * i; })
    | views::common; // convert a view iterator to a common one
```

**Problem Statement:** Given a heavily formatted `std::string` object, return the "raw" string without any overhead.  
Example input: `\r\n\n  Hello, world!  \n\n`; example output: `Hello, world!`

```C++
/* Define an adaptor which converts range to string */
template<typename Range>
std:string to_string(Range&& rng) {
    auto view = views::common(forward<Range>(rng));
    return std::string(view.begin(), v.end());
}

template<typename Range>
auto trim_front(Range&& rng) {
    // equivalence to the following:
    // forward<Range>(rng) | views::drop_while(::isspace);
    return views::drop_while(forward<Range>(rng), ::isspace);
}

template<typename>
auto trim_back(Range&& rng) {
    return forward<Range>(rng)
        | views::reverse
        | views::drop_while(::isspace)
        | views::reverse;
}

/* Define a custom trim adaptor function */
/* Specialized to call trim_back and trim_front functions */
template<typename Range>
auto trim(Range&& rng) {
    return forward<Range>(rng)
        | trim_front()
        | trim_back();
}

std::string trim_str(const std::string& str) {
    return str
        | trim()
        | rangesnext::to<std::string>;
}
```
