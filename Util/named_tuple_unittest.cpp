/**
 * @file named_tuple_unittest.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-06-14
 *
 * @copyright Copyright (c) 2023
 *
 */

// https://github.com/boost-ext/ut
#include "boost/ut.hpp"
#include "named_tuple.hpp"

int main(int argc, const char** argv)
{
    using namespace boost::ut;
    using util::type::namedtuple;

    "named tuple"_test = [] {
        should("allow empty") = [] {
            const auto nt = namedtuple{};
            expect(not [](auto t) { return requires { t[""_t]; }; }(nt));
        };

        should("support direct initialization") = [] {
            const auto nt = namedtuple{"price"_t = 42, "size"_t = 100};
            expect([](auto t) { return requires { t["price"_t]; }; }(nt));
            expect([](auto t) { return requires { t["size"_t]; }; }(nt));
            expect(not [](auto t) { return requires { t["quantity"_t]; }; }(nt));
            expect(42_i == nt["price"_t] and 100_i == nt["size"_t]);
        };

        should("support modification") = [] {
            auto nt       = namedtuple{"price"_t = int{}, "size"_t = std::size_t{}};
            nt["price"_t] = 12;
            nt["size"_t]  = 34u;
            expect(12_i == nt["price"_t] and 34_u == nt["size"_t]);
        };
    };

    return 0;
}
