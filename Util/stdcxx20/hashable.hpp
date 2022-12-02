/**
 * @file hashable.hpp
 * @author Xuhua Huang
 * @brief C++20 feature concepts to implement a template
 * to determine whether an object is 'hashable'.
 * @version 0.1
 * @date 2022-01-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <concepts> // require C++20 standard

namespace util {
    namespace type_safety {

        /* Templated concept to determine whether can call hash function on an object. */
        template<typename T>
        concept hashable = requires(T t) {
            { std::hash<T>{}(t) } -> std::convertible_to<std::size_t>;
        }

    } // end type_safety
} // end util
