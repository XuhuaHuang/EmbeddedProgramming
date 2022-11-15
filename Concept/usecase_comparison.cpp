/*****************************************************************//**
 * \file   usecase_comparison.cpp
 * \brief  Test basic concept implementation SupportComparison
 *
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#include "SupportsComparison.hpp"

namespace {

    template<typename T>
    requires std::copyable<T> && SupportsComparison<T>
    auto compare(T a, T b) {
        return a <=> b;
    }
}

auto main(void) -> int {
    if (::compare(1, 2)._Value == 0) {
        std::cout << "This should not happen" << "\n";
    }
    else if (::compare(1, 2)._Value < 0) {
        std::cout << "Indeed 1 is smaller than 2" << "\n";
    }
    else {
        std::cout << "No idea how this happened" << "\n";
    }

    return EXIT_SUCCESS;
}
