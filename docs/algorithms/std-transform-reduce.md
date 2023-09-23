# `std::transform_reduce`

https://en.cppreference.com/w/cpp/algorithm/transform_reduce

The algorithm `std::transform_reduce` first applies a unary callable to one or a binary callable to two ranges, and then a binary callable to the _resulting_ range.

https://godbolt.org/z/TerxjzE9s

```cxx
#include <algorithm>
#include <array>
#include <execution>
#include <iostream>
#include <locale>
#include <string>

constexpr std::array<std::string, 4U> strarr{"Only", "for", "testing", "purpose"};

int main()
{
    const std::size_t res = std::transform_reduce(
        std::execution::par,
        strarr.begin(),
        strarr.end(),
        0,
        [](std::size_t a, std::size_t b) { return a + b; },
        [](std::string s) { return s.size(); });

    std::cout.imbue(std::locale{"en_US.UTF8"});
    std::cout << "res = " << res << '\n';

    return 0;
}
```
