/*****************************************************************//**
 * \file   generic_add.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <stdlib.h>

#include <iostream>

/**
 * Lambda is an anonymous struct with the overloaded operator().
 * Consider the following example
 */
struct _anonymous_struct_add {
    template <typename T, typename U>
    constexpr auto operator()(T a, U b) const {
        return a + b;
    }
    // use it like this: constexpt const _anonymous_struct_add add = _anonymous_struct_add{};
};

int main(void) {
    constexpr auto add  = []<typename T>(T a, T b) -> T { return a + b; };
    constexpr auto add5 = [add](auto x) -> auto { return add(x, 5); };

    std::cout << add5(2) << "\n"; // 7

    return EXIT_SUCCESS;
}
