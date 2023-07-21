// cl .\any_of.hpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /exportHeader

#ifndef ANY_OF_HPP
#define ANY_OF_HPP

#include <algorithm>
#include <array>

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

#endif // !ANY_OF_HPP
