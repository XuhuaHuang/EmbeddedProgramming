// cl .\iterable_array.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// .\iterable_array.exe

#include <concepts>
#include <iostream>
#include <vector>

template<typename T>
concept is_iterable = requires (T array_like) {
    {
        array_like.has_next()
    } -> std::convertible_to<bool>;
    {
        array_like.next()
    } -> std::same_as<uint32_t>;
    {
        array_like.reset()
    };
};

template<is_iterable T>
std::size_t count(T array)
{
    array.reset();
    std::size_t count = 0;
    while (array.has_next())
    {
        array.next();
        count++;
    }
    return count;
}

template<typename T>
constexpr std::size_t count(T&& array)
{
    return count(array);
}

auto main(void) -> int
{
    return 0;
}
