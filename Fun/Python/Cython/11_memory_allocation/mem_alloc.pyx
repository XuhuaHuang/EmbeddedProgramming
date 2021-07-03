"""
About:
https://cython.readthedocs.io/en/latest/src/tutorial/memory_allocation.html
Cython notes on how to allocate memory

Xuhua Huang
July 3, 2021
"""

from _datetime import datetime

"""
Notes:
Simple C values and structs are usually allocated on the stack and passed by value
larger or more complicated objects must be manually requested and released

malloc(), realloc and free*( are implemented in Cython from "clibc.stdlib"
void* malloc(size_t size)
void* realloc(void* ptr, size_t size)
void free(void* ptr)
"""

import random
from libc.stdlib cimport malloc, free

def random_number(int number = 1):
    cdef int i = 0
    # allocate number * sizeof(double) bytes of memory
    cdef double *my_double_array = <double*> malloc(number * sizeof(double))
    if not my_double_array:
        raise MemoryError("Error! Not enough memory available for allocation!")
    
    try:
        random_num = random.normalvariate()
        random_num.seed(datetime())
        for i in range(number):
            my_double_array[i] = random_num(0, 1)

        return [x for x in my_double_array[:number]]  # using generator to return list
    
    finally:
        # return the previously allocated memory to the system
        free(my_double_array)