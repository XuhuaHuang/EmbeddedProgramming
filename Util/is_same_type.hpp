/*****************************************************************//**
 * \file   is_same_type.hpp
 * \brief  std::is_same<T, U>::value and std::is_same_v<T, U> impl.
 *
 * $ g++ is_same_type.hpp -std=c++2a
 *
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#ifndef IS_SAME_TYPE_HPP
#define IS_SAME_TYPE_HPP

#if __has_include(<typeinfo>)
#include <typeinfo>
#endif

namespace util::type {

    /**
     * Does the same thing as std::is_same<T, U>::value
     * and std::is_same_v<T, U> using typeid().hash_code().
     * No compile time optimization; higher runtime cost.
     * Do not do this in projects.
     */
    template<typename T, typename U>
    constexpr inline bool is_same_type(const T& t, const U& u) {
        return typeid(t).hash_code() == typeid(u).hash_code();
    }

}

#endif
