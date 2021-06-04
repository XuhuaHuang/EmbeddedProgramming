# Topic: decorators in python
# wrapper function using function objects
#
# Author: Xuhua Huang
# Last updated: Jun 4, 2021
# Created on: Jun 4, 2021

# wrap function around
# prepend function identity with fn.__name__ and str(id(fn))
# show execution process
import datetime
import time


def split_and_identity(fn):
    def wrapper():
        print(f"\nFunction: {fn.__name__}, id: {id(fn)} has started executing.")
        fn()
        print("Function ended executing")

    return wrapper  # return the wrapped around function objects


# decorator with arguments
def wrapper_with_args(fn):
    def wrapper(*args, **kwargs):  # argument strings, keyword arguments
        print(f"\nFunction: {fn.__name__}, id: {id(fn)} has started executing.")
        fn(*args, **kwargs)
        print("Function ended executing")

    return wrapper  # return the wrapped around function objects


# decorator with arguments and return type
def wrapper_with_args_return(fn):
    def wrapper(*args, **kwargs):  # argument strings, keyword arguments
        print(f"\nFunction: {fn.__name__}, id: {id(fn)} has started executing.")
        fn_return = fn(*args, **kwargs)
        print("Function ended executing")
        return fn_return

    return wrapper  # return the wrapped around function objects


def print_hello():
    print("Hello!")


@split_and_identity
def print_hello_world():
    print("Hello, world!")


# use decorator with arguments
@wrapper_with_args
def greet_user(user_name: str):
    print("Hello, ", user_name)


@wrapper_with_args_return
def add(x, y):
    return x + y


# create a timer decorator
def time_fn(fn):
    def wrapper(*args, **kwargs):
        print(f"\nFunction: {fn.__name__}, id: {id(fn)} has started executing.")
        time_before_calling = time.time()
        fn(*args, **kwargs)
        time_after_calling = time.time()
        print(f"Function ended executing. Took {time_after_calling - time_before_calling} seconds")

    return wrapper


# test recently created time_fn decorator
@time_fn
def sleep(secods: int):
    time.sleep(secods)


# create a very useful log decorator
def log(fn):
    def wrapper(*args, **kwargs):
        with open("my_logs.txt", "a") as file:
            file.write(f"Function called with arguments: {[str(arg) for arg in args]} at {datetime.datetime.now()}\n")
        fn_return = fn(*args, **kwargs)
        return fn_return

    return wrapper


@log
def main():
    wrapped_fn = split_and_identity(print_hello)  # a.k.a. function aliasing
    wrapped_fn()
    # equivalent: split_and_identify(print_hello)()
    split_and_identity(print_hello)()

    # call function that uses '@split_and_identify' syntax
    print_hello_world()

    # call function that uses '@wrapper_with_args' syntax
    greet_user("Lanfeng Jin")

    # call function that uses '@wrapper_with_args_return' syntax
    print(add(3, 4))

    # call function that uses '@time_fn' syntax
    sleep(7)  # awkward silence timing is 7 seconds


if __name__ == '__main__':
    main()
