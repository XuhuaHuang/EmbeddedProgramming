/**
 * @file safe_free.hpp
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Implementing our own free function from the standard library.
 * Setting the pointer to NULL after calling free() is a good idea.
 * The free() function does not check whether nor set the pointer to NULL.
 * 
 * $ g++ safe_free.hpp -std=c++2a
 * 
 * @version 0.9
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if __has_include(<stdlib.h>)
#include <stdlib.h>
#endif

namespace util {
    namespace pointer {

        /* Implement a better free() function to compensate the safety. */
        /* Requires explicit convertion to a (void**) for the pointer to free as function argument. */
        void safe_free(void** p_ptr) {
            /**
             * @brief argument is a pointer to a pointer (double pointer)
             * The address of the pointer gets copied into `p_ptr`
             * de-referncing p_ptr to access the 'original' pointer object.
             */
            if (p_ptr != NULL && *p_ptr != NULL) { // verify both double pointer and the original
                free(p_ptr);
                *p_ptr = NULL;
            }
        }

    } // end util::pointer
} // end util

/**
 * @brief Demonstration of this header file
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include "safe_free.hpp"
 * 
 * int main(void) {
 *     int* pi;
 *     pi = (int*)malloc(sizeof(int));
 *     *pi = 5;
 *     printf("Before: %p.\n", pi);
 *     util::pointer::safe_free((void**)&(pi));
 *     
 *     printf("After: %p.\n", pi);
 *     util::pointer::safe_free((void**)&(pi));
 *     
 *     system("pause");
 *     return (EXIT_SUCCESS);
 * }
 */
