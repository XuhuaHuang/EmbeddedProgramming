"""
Using an augmenting .pxd file allows to let original .py file completely untouched
.pyx and .pxd file must have the same name, otherwise will result in compile time error
untyped definitions in a .py file can be overridden and augmented with static types in .pxd

if a .pxd file is found with the same name as the .py file being compiled, it will be searched for cdef classes
and cdef/def functions and methods
for example, augmenting.py will be converted to the signature/prototype specified in augmenting.pxd

Xuhua Huang
Last updated: July 25, 2021
TODO: Magic attributes
https://cython.readthedocs.io/en/latest/src/tutorial/pure.html#magic-attributes
"""


def my_function(x, y=2):
    a = x - y
    return a + x * y


def _helper(a):
    return a + 1


class Example:
    def __init__(self, b=0):
        self.a = 3
        self.b = b

    def invoke_helper(self, x):
        print(x + _helper(1.0))