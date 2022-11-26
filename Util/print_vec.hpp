/*****************************************************************//**
 * \file   print_vec.hpp
 * \brief  Template function to print std::vector of any types.
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#ifndef PRINT_VEC_HPP
#define PRINT_VEC_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef DEBUG
#define DEBUG(arg_str) std::cout << arg_str << "\n";
#endif

namespace util {
    namespace vector {

        /* Template to print a std::vector with O(n). */
        /* For sanity, using constant reference instead of iterators. */
        template<typename T>
        static void print_vec(const std::vector<T>& arg_vec) {
            DEBUG("\n[fn]util::vector::print_vec");

            /* Loop through the vector with range-based for loop. */
            for (const T& t : arg_vec)
            {
                std::cout << t << ", ";
            }

            DEBUG("\n[fn]Finished printing vector.");
            return; // add empty return statement for consistency.
        }

    } // end Util::vector
} // end Util

#endif
