// cl .\iterable_array.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// .\iterable_array.exe

#include <concepts>
#include <iostream>
#include <tuple>
#include <utility>
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
constexpr std::size_t count(T array)
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

struct iterable_array
{
    inline constexpr iterable_array() noexcept                      = default;
    inline constexpr iterable_array(const iterable_array&) noexcept = default;
    inline constexpr iterable_array(const std::size_t s)
        : array(s)
    {
    }
    inline constexpr ~iterable_array() noexcept = default;

    std::vector<uint32_t> array{};
    std::size_t           index = 0;

    inline constexpr void          reset() { index = 0; }
    inline constexpr bool          has_next() const noexcept { return index < array.size(); }
    inline constexpr std::uint32_t next()
    {
        index++;
        return array[index - 1];
    }
};

consteval [[nodiscard]] std::size_t __cdecl count_iterable_array()
{
    static_assert(std::is_constant_evaluated());
    return count(iterable_array(10));
}

namespace std
{

template<>
struct tuple_size<iterable_array> : integral_constant<std::size_t, 2>
{
};

template<>
struct tuple_element<0U, iterable_array>
{
    using type = vector<uint32_t>;
};

template<>
struct tuple_element<1U, iterable_array>
{
    using type = size_t;
};

template<size_t I>
    requires (I < tuple_size<iterable_array>::value)
typename tuple_element<I, iterable_array>::type& get(iterable_array& itrarray)
{
    if constexpr (I == 0)
        return itrarray.array;
    else /* constexpr */
        return itrarray.index;
}

template<size_t I>
    requires (I < tuple_size<iterable_array>::value)
typename const tuple_element<I, iterable_array>::type& get(const iterable_array& itrarray)
{
    if constexpr (I == 0)
        return itrarray.array;
    else /* constexpr */
        return itrarray.index;
}
} // namespace std

auto main(void) -> int
{
    return 0;
}
