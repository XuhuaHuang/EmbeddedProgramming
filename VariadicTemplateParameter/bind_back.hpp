// cl .\bind_back.hpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /exportHeader
// output: bind_back.hpp.ifc

// g++ .\bind_back.hpp -std=c++2b -Wall -Wextra -O3 -Wno-pragma-once-outside-header
// output: bind_back.hpp.gch

#include <type_traits>

[[nodiscard]] constexpr auto bind_back(auto&& fn, auto&&... back_args)
{
    return [fn = std::forward<decltype(fn)>(fn), ... back_args = std::forward<decltype(back_args)>(back_args)](
               auto&&... front_args) { return std::invoke(fn, front_args..., back_args...); };
}
