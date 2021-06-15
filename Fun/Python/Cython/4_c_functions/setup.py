from setuptools import setup
from Cython.Build import cythonize

''' 
Dynamically link libc library with setuptools
    configure build ssytem to link the shared library 'm'
    add to the 'libraries' parameter of the 'Extension()'
'''

'''
ext_modules = [
    Extension(
        "Calling C funtions",
        source=["c_functions.pyx"],
        libraries=['m']  # Unix-like specific system
    )
]
'''

setup(
    name='Calling C funtions',
    ext_modules=cythonize("c_functions.pyx"),
    zip_safe=False,
)