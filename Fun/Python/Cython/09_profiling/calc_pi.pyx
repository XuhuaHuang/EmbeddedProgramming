# cython: profile=True
from numpy import double
cimport cython


# disabling profiling function wise
@cython.profile(False)
cdef inline double recip_square(int i) except -1.0:
    return 1. / double(i ** 2)


def approx_pi(int n = 10000000):
    cdef double val = 0
    cdef int k
    for k in range(1, n + 1):
        val += recip_square(k)
    return (6 * val) ** .5