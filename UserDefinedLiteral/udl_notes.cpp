/**
 * @file udl_notes.cpp
 * @author Xuhua Huang
 * @brief Motes and demonstration on "User Defined Literals" in C++20.
 * @version 0.1
 * @date 2022-01-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<stdlib.h>

/* Forward Declaration; To be implemented later. */
class Temperature {
public:
    Temperature() = default;
    Temperature(const double value) {
        this->value_with_udl = value;
    }
    double value_with_udl;
    inline operator double() {
        return this->value_with_udl;
    }
};

/**
 * @brief The following 2 user-defined literals shared the same strings
 * Convention is to put them into different namespaces to prevent pollution.
 */
namespace geometry_namespace {
    constexpr double operator""_deg(long double);
}

namespace temperature_namespace {
    Temperature operator""_deg(long double value) {
        return Temperature(value);
    }
}

auto main(void) -> int {

    using namespace geometry_namespace;
    double right_angle = 90.0_deg; // unambiguously an angle, not a temperature

    // start a new scope
    {
        using namespace temperature_namespace;
        Temperature room_temperature(26.0_deg);
    }

    {
        using namespace std::literals;
        static_assert(1h == 60m);
        static_assert(1h == 3600s);

        static_assert(std::is_same<decltype("hello"sv), std::string_view>::value);
    }

    system("pause");
    return EXIT_SUCCESS;
}

/* Build a base-3 number interpreter */
namespace base3_namespace {

    consteval int operator""_3(const char* digits) {
        int ret = 0;
        for (char c = *digits; c != NULL; c = *++digits) {
            if ('\'' == c) continue; // ignore digit separator
            if (c < '0' || '2' < c)
                throw std::out_of_range("Invalid base-3 digit.");
            if (ret >= (std::numeric_limits<int>::max() - (c - '0')) / 3)
                throw std::overflow_error("Integer overflow");
            ret = 3 * ret + (c - '0');
        }
        return ret;
    } // end udl

} // end namespace

/* ---------------------------- */
/* String UDL Operator Template */
/* ---------------------------- */
struct IPv4Addr
{
    // calling syntax:
    // IPv4Addr::isIPv4Format(const char*)
    static constexpr bool isIPv4Format(const char* str);
    explicit constexpr IPv4Addr(const char* str) {}
    // ...
};

struct IPv6Addr
{
    explicit constexpr IPv6Addr(const char* str) {}
    // ...
};

/* Define a custom string proxy to be used in UDL template */
template<typename CharT, std::size_t N>
struct StrLiteralProxy
{
    // Requires a compile-time constant to construct the member array
    // Therefore, define a constexpr constructor to guarantee it
    constexpr StrLiteralProxy(const CharT (&s)[N]) {
        std::copy(std::begin(s), std::end(s), std::begin(m_data));
    }

    constexpr std::size_t size() const { return N - 1; }
    constexpr const CharT* data() const { return m_data; }

private:
    CharT m_data[N];
};

/* Operator Template */
/* Template type deduction happens during compile time. */
template<StrLiteralProxy slp>
constexpr auto operator""_IP() {
    return std::conditional<IPv4Addr::isIPv4Format(slp.data()),
        IPv4Addr, IPv6Addr>(slp.data());
}

// auto v4 = "1.2.3.4"_IP;      // type deducted to IPv4
// auto v6 = "1::2::3::4"_IP    // type deducted to IPv6
