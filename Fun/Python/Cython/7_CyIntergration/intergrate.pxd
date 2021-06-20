'''
Cython uses '.pxd' file as a C-style header
it is meant to accompanying .pyx source file
'''

from libc.math cimport sin
from Cython.Shadow import inline

cdef class Function:
    cpdef inline double evaluate(self, double x) except *:
        return 0
    
    
cpdef integrate(Function f, 
                double a,
                double b, 
                int N)