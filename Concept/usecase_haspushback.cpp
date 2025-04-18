/*****************************************************************//**
 * \file   usecase_haspushback.cpp
 * \brief  Test basic concept implementation HasPuchBack
 *
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#include <set>
#include <vector>

#include "HasPushBack.hpp"

namespace {

    }

    /* Ad-hoc style HasInsert concept implementation */
    template<typename Coll>
    concept HasInsert = requires (Coll & c, typename Coll::value_type val) {
        c.insert(val);
    };

    void coll_append(::HasInsert auto& coll, const auto& val) {
        coll.insert(val);
        return;
    }
}
auto main(void) -> int {
    std::vector<int> v{ 0, 1 };
    std::set<int> s{ 0, 1 };

    ::coll_append(v, 2); // calls coll_append(HasPushBack ...) variant
    ::coll_append(s, 2); // calls coll_append(HasInsert ...) variant

    std::cout << "print coll_append HasPushBack variant: ";
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n" << "print coll_append HasInsert variant: ";
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }

    return EXIT_SUCCESS;
}
