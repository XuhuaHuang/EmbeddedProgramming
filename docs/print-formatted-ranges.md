# Print Formatted Ranges with `std::format`

<https://godbolt.org/z/c44b4bvj4>

```cpp
#include <format>
#include <iostream>
#include <vector>

int main()
{
    std::vector v = {1, 2, -1, -4};
    std::cout << std::format("v: {}", v) << "\n";

    return 0;
}
```
