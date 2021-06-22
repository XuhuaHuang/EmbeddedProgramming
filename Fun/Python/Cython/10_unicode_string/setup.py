from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    name='Unicode strings',
    ext_modules=cythonize("c_func.pyx"),
    zip_safe=False,
)