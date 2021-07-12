# Typing in Python for better code efficiency
# Author: Xuhua Huang
#
# Last updated: July 12, 2021
# Created on: July 12, 2021
#

import math
import typing
from typing import NoReturn, Optional

""" I can finally use my favorite trailing return type in Python! """


def greet_user(name: str) -> str:
    return "Hello, {}".format(name.lower())


"""
Special typing primitives
Can be used as types in annotations and do not support [] operator
"""


def halt_program() -> NoReturn:
    raise SystemExit(0)


""" Optional argument """
# just like in C/C++, variable with default arguments
# must be placed at the end of the positional argument list
class Vector:
    scalar_constant: float = 1.00

    def __init__(self, x_coord, y_coord):
        self.x = x_coord
        self.y = y_coord

    def change_scalar(self, new_scalar: float):
        if 0 < new_scalar < math.inf:
            self.scalar_constant = new_scalar

    def apply_scalar(self, cls):
        self.x *= cls.scalar_constant
        self.y *= cls.scalar_constant


def rescale_vec(vec: Vector, scalar: float = 1.00) -> None:
    vec.change_scalar(scalar)
    vec.apply_scalar()


def main():
    print(greet_user('Lanfeng'))

    try:
        halt_program()
    except SystemExit:
        print("Expected error occur")


if __name__ == '__main__':
    main()
