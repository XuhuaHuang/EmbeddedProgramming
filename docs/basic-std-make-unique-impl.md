# Basic `std::make_unique`

`std::make_shared` is part of C++11, however, `std::make_unique` is part of the Standard Library as of C++14.

A typical `std::make_unique` implementation would look like the following:

```cpp
template<typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&.. params)
{
    return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}
```
