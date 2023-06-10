# Chaining with Deducing-this

```cpp
#include <iostream>
#include <vector>

struct less_than {
    template<typename T, typename U>
    bool operator()(this less_than, const T& lhs, const U& rhs) {
        return lhs < rhs;
    }
};

// disclaimer: do not inherit from std::vector types
// in production code
struct my_vector : public std::vector<int> {
    using std::vector<int>::vector;

    auto sorted_by(this my_vector self, auto cmp) -> my_vector {
        std::sort(self.begin(), self.end(), cmp);
        return self;
    }
};
```

the calling code will look like the following:

```cpp
my_vector{3, 1, 4, 1, 5, 9, 2, 6, 5}.sorted_by(less_than);
```

```cpp
template<typename Derived, typename Base>
concept derived_from =
    std::is_base_of<Base, Derived> and
    std::is_convertible_v<const volatile Derived*, const volatile Base>
```
