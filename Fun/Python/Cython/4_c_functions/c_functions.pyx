from libc.stdlib cimport atoi
from cpython.version cimport PY_VERSION_HEX
from libc.math cimport sin

cdef double f(double x):
    return sin(x * x)


# Python version >= 3.2 final ?
print(PY_VERSION_HEX >= 0x030200F0)


'''
atio() function is defined in stdlib.h
standard cimportfiles in Cython's source package Cython/Includes/
also stored in .pxd files
'''
cpdef int parse_charptr_to_py_int(char* s):
    assert s is not NULL, "Error! Byte string is NULL"
    return atoi(s)


''' external declaration for sin() function'''
cdef extern from "math.h":
    cpdef double sin(double x)
'''
>>>sin(0)
0.0
'''

'''
Naming parameters
Both C and Cython support signature declarations without parameter names
'''
cdef extern from "string.h":
    char* strstr(const char*, const char*)
'''
However, this prevents Cython code from calling it with keyword arguments.
It is therefore preferable to write the declaration like this instead:
'''
cdef extern from "string.h":
    char* strstr(const char *haystack, const char *needle)
