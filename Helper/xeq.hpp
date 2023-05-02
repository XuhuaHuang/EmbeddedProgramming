#include <concepts>
#include <source_location>

namespace util
{

constexpr decltype(auto) value(auto& op)
{
    if constexpr (requires { op.value; })
        return op.value;
    else
        return op;
}

auto error(const auto& expr, const std::source_location& location) -> void
{
    std::cerr << location.file_name() << ":" << location.line() << ":FAILED: " << expr << "\n";
}

template<typename TLhs, typename TRhs>
    requires std::is_default_constructible<TLhs>::value && std::is_default_constructible<TRhs>::value
struct eq final
{
    TLhs                 lhs{};
    TRhs                 rhs{};
    std::source_location location_{};

    constexpr ~eq() noexcept(std::is_nothrow_destructible<TRhs>::value&& std::is_nothrow_destructible<TRhs>::value)
    {
        if (not *this)
            error(*this, location_);
    }

    [[nodiscard]] constexpr explicit(false) operator bool() const { return value(lhs) == value(rhs); }

    friend std::ostream& operator<<(std::ostream& os, const eq& op)
    {
        return (os << value(op.lhs) << " == " << value(op.rhs));
    }
};

template<typename TLhs, typename TRhs>
eq(TRhs, TRhs) -> eq<TLhs, TRhs>;

} // namespace util
