// cl .\bind_back.hpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /exportHeader
// output: bind_back.hpp.ifc

#include <type_traits>

[[nodiscard]] constexpr auto bind_back(auto&& fn, auto&&... back_args)
{
    return [fn = std::forward<decltype(fn)>(fn), ... back_args = std::forward<decltype(back_args)>(back_args)](
               auto&&... front_args) { return std::invoke(fn, front_args..., back_args...); };
}
