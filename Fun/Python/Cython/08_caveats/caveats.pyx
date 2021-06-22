'''
https://cython.readthedocs.io/en/latest/src/tutorial/caveats.html
if given two ints a and b as the following:
cdef int a
cdef int b
a % b has the same type as the second argument following Python semantics
'''

cdef unsigned int n = 10
print(range(-n, n))  # prints an empty list
# -n wraps around to a +INF prior to parsing to the range() function