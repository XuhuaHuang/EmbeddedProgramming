from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Embedded C++ Application demo',
    ext_modules=cythonize("embedded.pyx"),
    zip_safe=False,
)