#pragma once

#include <cassert>
#include <cstddef>
#include <string_view>

namespace util
{

struct string_literal
{
public:
    template<std::size_t N>
    explicit(false) consteval string_literal(const char (&str)[N]) noexcept
        : size_(N - 1)
        , cstr_(str)
    {
        assert(*std::next(cstr_, N - 1) == '\0');
    }

    constexpr StringLiteral() noexcept
        : size_(0)
        , cstr_("")
    {
    }

    [[nodiscard]] constexpr std::size_t size() const { return size_; }

    [[nodiscard]] constexpr const char* c_str() const { return cstr_; }
    explicit(false) constexpr operator const char*() const { return c_str(); }

    [[nodiscard]] constexpr std::string_view as_view() const { return {cstr_, size_}; }
    explicit(false) constexpr operator std::string_view() const { return as_view(); }

private:
    std::size_t size_;
    const char* cstr_;
};

} // namespace util
