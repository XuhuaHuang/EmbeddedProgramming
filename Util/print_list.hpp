/*****************************************************************//**
 * \file   print_list.hpp
 * \brief  Template function to print std::list of any types.
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#ifndef PRINT_LIST_H
#define PRINT_LIST_H

#include <iostream>
#include <list>

#ifndef DEBUG
#define DEBUG(arg_str) std::cout << arg_str << "\n";
#endif

namespace util {
    namespace list {

        /* Template to print a std::list with O(n). */
        /* For sanity, using constant reference instead of iterators. */
        template<typename T>
        static void print_list(std::list<T> arg_list) {
            DEBUG("\n[fn]util::list::print_list");

            /* Loop through the vector with iterator. */
            typename std::list<T>::iterator iter; // keyword "typename" is required for iterator
            for (iter = arg_list.begin(); iter != arg_list.end(); ++iter)
                std::cout << *iter << ", "; // dereference the iterator to print content

            DEBUG("\n[fn]Finished printing the list.");
            return;
        }

    } // end Util::list
} // end Util


#endif