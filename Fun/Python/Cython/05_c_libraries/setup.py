from setuptools import Extension, setup
from Cython.Build import cythonize

setup(
    name='Using C libraries',
    ext_modules=cythonize([Extension("queue", ["queue.pyx"])]),
    zip_safe=False,
)
