from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    name='Cdef classes',
    ext_modules=cythonize("cdef_class.pyx"),
    zip_safe=False,
)