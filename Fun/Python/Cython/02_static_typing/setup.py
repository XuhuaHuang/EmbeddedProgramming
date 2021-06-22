from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Static typing demo',
    ext_modules=cythonize("static_typing.pyx"),
    zip_safe=False,
)
