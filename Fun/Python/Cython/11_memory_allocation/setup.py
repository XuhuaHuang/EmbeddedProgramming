from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Memory allocation demo',
    ext_modules=cythonize("mem_alloc.pyx"),
    zip_safe=False,
)