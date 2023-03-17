# `std::expected` Cheatsheet

## With `std::vector`

```C++
#include <algorithm>
#include <vector>

auto main(void) -> int {
    std::vector<int> vec { /* ... */ };
    auto sum = std::accumulate(vec.begin(), vec.end(), 0,
        [](int a, int b) -> std::expected<int, numeric_error> {
            if (b > 0 && a > INT_MAX - b) return std::unexpected(signed_integer_overflow);
            if (b < 0 && a < INT_MIN - b) return std::unexpected(signed_integer_underflow);
            return a + b;
        }
    );

    return 0;
}
```

## In the Context of Error Handling

```C++
auto get_widget() -> std::expected<Widget, std::variant<ParseError, IOError, NetworkError>>;

auto widget = get_widget();

template <typename... Ts> struct overload : Ts... {
    using Ts::operator()...;
};

if (widget.has_value()) {
    process(widget.value());
}
else {
    std::visit(overload{
        [](ParseError& error) {
            // handle parse error ...
        },
        [](IOError& error) {
            // handle I/O error ...
        },
        [](NetworkError& error) {
            // handle network error ...
        }
    }, widget.error());
}
```
