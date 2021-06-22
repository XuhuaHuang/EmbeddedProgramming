from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Prime numbers demo',
    ext_modules=cythonize("primes.pyx"),
    zip_safe=False,
)