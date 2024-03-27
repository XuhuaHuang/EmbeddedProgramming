// cl .\any_of.hpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /exportHeader

#ifndef ANY_OF_HPP
#define ANY_OF_HPP

#include <algorithm>
#include <array>
#include <tuple>

template<typename T = int, typename... Vs>
struct any_of
{
private:
    std::array<T, sizeof...(Vs)> values;

public:
    any_of(Vs... vs)
    {
        if constexpr (sizeof...(Vs))
        {
            this->values = std::array{vs...};
        }
    }

    constexpr bool operator==(const T& other)
    {
        return std::any_of(std::cbegin(this->values), std::cend(this->values), [&other](auto x) { return x == other; });
    }
};

namespace experimental
{

template<class... Ts>
struct any_of
{
    any_of(Ts... args)
        : args{args...}
    {
    }

    auto operator==(auto rhs) const
    {
        return std::apply([&](auto... lhs) { return (... or (lhs == rhs)); }, args);
    }

private:
    std::tuple<Ts...> args;
};

} // namespace experimental

#endif // !ANY_OF_HPP
