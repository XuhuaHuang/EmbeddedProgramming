from libc.math cimport sin
from Cython.Shadow import inline

cdef class Function:
    cpdef inline double evaluate(self, double x) except *:
        return 0
    
    
cdef class SinOfSquareFn(Function):
    cpdef inline double evaluate(self, double x) except *:
        return sin(x**2)
    
'''
A cpdef function is fully overridable
by methods and instance attribute in Python classes
'''