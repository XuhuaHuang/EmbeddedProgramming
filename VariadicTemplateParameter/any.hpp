#include <concepts>

struct Any
{
    // template<typename T>
    // operator T();

    template<typename T>
    operator T&() /* const */ volatile;

    template<typename T>
    operator T&&();
};

template<typename T, std::size_t Idx>
using repeated_with = T;

template<typename T, std::size_t N>
concept ConstructibleWithN = requires {
    []<std::size_t... Idxs>(std::index_sequence<Idxs...>)
        requires requires {
            // try to construct T with N objects convertible to anything
            T{repeated_with<Any, Idxs>{}...};
        }
    {
    }
    (std::make_index_sequence<N>{});
};

struct Bar
{
    Bar(int, int);
};
static_assert(ConstructibleWithN<Bar, 2>);

// this is valid code
// because it finds the implicit generated copy and move constructor
static_assert(ConstructibleWithN<Bar, 1>);

struct Baz
{
    int i;
    int j;
};
static_assert(ConstructibleWithN<Baz, 2>);

template<typename T, size_t N>
concept AggregateOfN = std::is_aggregate_v<T> && ConstructibleWithN<T, N> && not ConstructibleWithN<T, N + 1>;
