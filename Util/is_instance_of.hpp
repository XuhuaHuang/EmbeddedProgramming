/*****************************************************************//**
 * \file   is_instance_of.hpp
 * \brief  Implementation of popular Python function isinstance()
 * Identify whether an object is of some specific types
 * Base of a C++11 function std::is_base_of<Base, T>::value
 * 
 * $ g++ is_instance_of.hpp -std=c++2a
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#ifndef IS_INSTANCE_OF_HPP
#define IS_INSTANCE_OF_HPP

#include <iostream>

namespace util {
    namespace type {

        /* Template to determine the type of parsed object. */
        template<typename Base, typename T>
        inline bool is_instance_of(const T&) {
            return std::is_base_of<Base, T>::value;
        }

    } // end util::type
} // end util

#endif