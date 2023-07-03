#pragma once

template<typename T, auto N>
[[nodiscard]] consteval auto array_size(T (&)[N])
{
    return N;
}

template<typename T>
    requires requires { std::declval<T>().size(); }
[[nodiscard]] constexpr auto array_size(T&& t)
{
    return t.size();
}
