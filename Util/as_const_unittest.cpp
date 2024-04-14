/**
 * @file as_const_unittest.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-04-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "as_const.hpp"

#include <cassert>
#include <string>
#include <type_traits>
#include <utility>

int main()
{
    using util::type_safety::as_const;

    std::string mutable_str = "Hello World!";
    auto&&      const_ref   = as_const(mutable_str);

    mutable_str.clear(); // OK
    // clang-format off
    //  const_ref.clear(); // Error: 'const_ref' is 'const' qualified,
                           //        but 'clear' is not marked const
    // clang-format on

    assert(&const_ref == &mutable_str);
    assert(&as_const(mutable_str) == &mutable_str);

    using ExprType = std::remove_reference_t<decltype(as_const(mutable_str))>;

    static_assert(std::is_same_v<std::remove_const_t<ExprType>, std::string>,
                  "ExprType should be some kind of string.");

    static_assert(!std::is_same_v<ExprType, std::string>, "ExprType shouldn't be a mutable string.");

    return 0;
}
