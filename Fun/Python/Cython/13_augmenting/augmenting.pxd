"""
This file contains Cython style definition for classes and methods defined in
'augmenting.py'
"""

cpdef int my_function(int x, int y = *) # python visible function
cdef double _helper(double a)

cdef class Example:
    cdef public int a, b
    cpdef invoke_helper(self, double x)