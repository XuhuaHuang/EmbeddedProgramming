# Virtual namespaces and decorators
# for function overloading
# Author: Xuhua Huang
#
# Last updated: Jun 1, 2021
# Created on: Jun 1, 2021

from inspect import getfullargspec
import math
import time


class Function(object):
    """
    Function class is a wrap over standard python function
    """

    def __init__(self, fn):
        self.fn = fn

    def __call__(self, *args, **kwargs):
        """
        when invoked like a function it internally invokes
        the wrapped function and returns the returned value
        """
        return self.fn(*args, **kwargs)

    def key(self, args=None):
        """
        Returns the key that will uniquely identify
        a function (even when it is overloaded)
        """
        # if args not specified, extract the arguments from the
        # function definition
        if args is None:
            args = getfullargspec(self.fn).args

        return tuple([
            self.fn.__module__,
            self.fn.__class__,
            self.fn.__name__,
            len(args or []),
        ])


class Namespace(object):
    """
    Namespace is the singleton class that is responsible
    for holding all the functions
    """
    __instance = None

    def __init__(self):
        if self.__instance is None:
            self.function_map = dict()
            Namespace.__instance = self
        else:
            raise Exception("Cannot instantiate a virtual Namespace again")

    @staticmethod
    def get_instance():
        if Namespace.__instance is None:
            Namespace()
        return Namespace.__instance

    def register(self, fn) -> Function:
        """
        registers the function in the virtual namespace and returns
        an instance of callable Function that wraps the function fn.
        """
        fn = Function(fn)
        self.function_map[fn.key()] = fn
        return fn

    def get(self, fn, *args):
        """
        get returns the matching function from the virtual namespace
        return None if it did not fund any matching function
        """
        func = Function(fn)
        return self.function_map.get(func.key(args=args))


def my_decorator(fn):
    """
    my_decorator is a custom decorator that wraps any function
    and prints on stdout the time for execution
    """

    def wrapper_function(*args, **kwargs):
        start_time = time.time()

        # invoking the wrapped function and getting the return value
        value = fn(*args, **kwargs)
        print("the function execution took:", time.time() - start_time, "seconds")

        # returning the value got after invoking the wrapped function
        return value

    return wrapper_function


def overload(fn) -> Function:
    """
    overload is the decorator that wraps the function
    and returns a callable object of type Function
    """
    return Namespace.get_instance().register(fn)


def __call__(self, *args, **kwargs):
    """
    Overriding the __call__ function
    makes the instance callable.
    """
    # fetching the function to be invoked from the virtual namespace
    # through the arguments.
    fn = Namespace.get_instance().get(self.fn, *args)
    if not fn:
        raise Exception("No matching function found.")


@overload
def area(length: float, width: float):
    return length * width


@overload
def area(radius: float):
    return math.pi * radius ** 2


def main():
    area(7)
    area(3, 4)


if __name__ == '__main__':
    main()
