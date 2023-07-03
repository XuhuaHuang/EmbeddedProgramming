#pragma once

namespace util
{
namespace type_safety
{

struct movable
{
    constexpr movable()                                     = delete;
    constexpr movable(const movable&)                       = delete;

    consteval movable(movable&&)                            = default;
    consteval auto operator=(movable&&) -> movable&         = default;

    constexpr auto operator=(const movable&) -> movable&    = delete;
    constexpr auto operator==(const movable&) const -> bool = delete;
};

struct not_movable
{
    consteval not_movable()                                      = default;
    consteval not_movable(const not_movable&)                    = default;

    constexpr not_movable(not_movable&&)                         = delete;
    constexpr auto operator=(not_movable&&) -> not_movable&      = delete;

    constexpr auto operator=(const not_movable&) -> not_movable& = default;
    constexpr auto operator==(const not_movable&) const -> bool  = default;
};

struct copyable
{
    constexpr copyable()                                     = delete;

    consteval copyable(const copyable&)                      = default;
    consteval copyable(copyable&&)                           = default;
    consteval auto operator=(copyable&&) -> copyable&        = default;
    consteval auto operator=(const copyable&) -> copyable&   = default;

    constexpr auto operator==(const copyable&) const -> bool = delete;
};

struct not_copyable
{
    constexpr not_copyable()                                       = default;

    consteval not_copyable(const not_copyable&)                    = delete;
    consteval not_copyable(not_copyable&&)                         = delete;
    consteval auto operator=(not_copyable&&) -> not_copyable&      = delete;
    consteval auto operator=(const not_copyable&) -> not_copyable& = delete;

    constexpr auto operator==(const not_copyable&) const -> bool   = default;
};

struct not_semiregular
{
    constexpr not_semiregular()                                          = delete;
    constexpr not_semiregular(const not_semiregular&)                    = delete;
    constexpr not_semiregular(not_semiregular&&)                         = delete;
    constexpr auto operator=(not_semiregular&&) -> not_semiregular&      = delete;
    constexpr auto operator=(const not_semiregular&) -> not_semiregular& = delete;

    constexpr auto operator==(const not_semiregular&) const -> bool      = default;
};

struct semiregular
{
    constexpr semiregular()                                      = default;
    constexpr semiregular(const semiregular&)                    = default;
    constexpr semiregular(semiregular&&)                         = default;
    constexpr auto operator=(semiregular&&) -> semiregular&      = default;
    constexpr auto operator=(const semiregular&) -> semiregular& = default;

    constexpr auto operator==(const semiregular&) const -> bool  = delete;
};

struct not_regular
{
    constexpr not_regular()                                      = delete;
    constexpr not_regular(const not_regular&)                    = delete;
    constexpr not_regular(not_regular&&)                         = delete;
    constexpr auto operator=(not_regular&&) -> not_regular&      = delete;
    constexpr auto operator=(const not_regular&) -> not_regular& = delete;
    constexpr auto operator==(const not_regular&) const -> bool  = delete;
};

struct regular
{
    constexpr regular()                                     = default;
    constexpr regular(const regular&)                       = default;
    constexpr regular(regular&&)                            = default;
    constexpr auto operator=(regular&&) -> regular&         = default;
    constexpr auto operator=(const regular&) -> regular&    = default;
    constexpr auto operator==(const regular&) const -> bool = default;
};

} // namespace type_safety
} // namespace util
