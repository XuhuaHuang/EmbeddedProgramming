#ifndef DESIGN_BY_INTROSPECTION_SYS_HPP
#define DESIGN_BY_INTROSPECTION_SYS_HPP

#include <concepts>

namespace util
{

struct sys
{
private:
    using condition_t     = auto (*)(int) -> bool;
    condition_t condition = nullptr;

    template<typename T>
    constexpr static inline bool always_false = false;

public:
    template<typename T>
    constexpr auto process(const T& t)
    {
        if constexpr (requires { condition = t; })
        {
            condition = t;
        }
        else if constexpr (requires { condition(t.price); })
        {
            return condition and condition(t.price);
        }
        else
        {
            static_assert(always_false<T>, "Incorrect argument to process");
        }
    }
};

} // namespace util

#endif // !DESIGN_BY_INTROSPECTION_SYS_HPP
