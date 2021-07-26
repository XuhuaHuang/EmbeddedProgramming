from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Augmenting .py and .pxd demo',
    ext_modules=cythonize("augmenting.py"),
    zip_safe=False,
)