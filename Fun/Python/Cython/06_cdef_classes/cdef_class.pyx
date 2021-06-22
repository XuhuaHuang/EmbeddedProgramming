from libc.math cimport sin
from cdef_class cimport Function, SinOfSquareFn
from numpy.polynomial.tests.test_classes import classes

'''
As expected, Cython supports pure Python class definitions
Example is provided as listed:
'''

class MathFunction(object):
    def __init__(self, name, operator):
        self.name = name
        self.operator = operator

    def __call__(self, *operands):
        return self.operator(*operands)
    
'''
Normal Python classes can herite from cdef classes, not the other way around
Cython is restricted to single inheritance
Python classes can inherit from any number of Python classes and extention types
in both Python and Cython code
'''

'''
The following code is moved to file named "sin_of_square.pxd"  
cdef class Function:
    cpdef double evaluate(self, double x) except *:
        return 0
    
    
cdef class SinOfSquareFn(Function):
    cpdef double evaluate(self, double x) except *:
        return sin(x**2)
'''


def intergrate(Function f, double a, double b, int N):
    cdef int i
    cdef double s, dx
    if f is None:
        raise ValueError("Function object f can not be found.")
    s = 0
    dx = (b - a) / N
    for i in range(N):
        s += f.evaluate(a + i * dx)
    return s * dx

print(intergrate(SinOfSquareFn(), 0, 1, 10000))


cdef class WaveFunction(Function):

    # Not available in Python-space:
    cdef double offset

    # Available in Python-space:
    cdef public double freq

    # Available in Python-space, but only for reading:
    cdef readonly double scale

    # Available in Python-space:
    @property
    def period(self):
        return 1.0 / self.freq

    @period.setter
    def period(self, value):
        self.freq = 1.0 / value