'''
https://cython.readthedocs.io/en/latest/src/tutorial/strings.html
Cython separates byte strings and unicode strings
Cython supports byte string, str, unicode and basestring

note that basestring type represents both str and unicode

Xuhua Huang
June 22, 2021
'''

from libc.stdlib cimport malloc
from libc.string cimport strcpy, strlen

# Python string prefixes:
# b'byte' - byte strings
# u'text' for unicode strings
# f'formatted {value} for formatted unicode string literals

'''
Passing Byte strings
'''
cdef char* hello_world = 'Hello world'
cdef Py_ssize_t n = strlen(hello_world)

'''
C function call with return type of character array
'''
cdef char* c_call_returning_c_string():
    cdef char* c_string = <char*>malloc((n + 1) * sizeof(char))
    if not c_string:
        raise MemoryError('Array Memory Allocation Failed')
    
    strcpy(c_string, hello_world)
    return c_string

cdef void get_c_string(char** c_string_ptr, Py_ssize_t* length):
    c_string_ptr[0] = <char*> malloc((n + 1) * sizeof(char))
    if not c_string_ptr[0]:
        raise MemoryError('Array Memory Allocation Failed')
    
    strcpy(c_string_ptr[0], hello_world)
    length[0] = n