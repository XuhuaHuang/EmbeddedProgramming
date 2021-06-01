# Topic: Overloading built-in methods
# Author: Xuhua Huang
#
# Last updated: May  31, 2021
# Created on: May 31, 2021

"""
depending upon the parameters passed
a different piece of code executes inside the function
"""

import math


class Student:
    """
    def __init__(self):
        self.name = 'unknown'
        self.student_id = 'unknown'
        self.major = 'unknown'
        print("Default constructor" + Student.__init__())
    """

    def __init__(self, name: str, student_id: int, major: str):
        self.name = name
        self.student_id = student_id
        self.major = major
        print("Overloaded constructor" + str('Student.__init__(self, name, student_id, major)'))

    def say_hello(self, name=None):  # provide default argument to act as an overload
        if name is not None:
            print('Hello ' + name)
        else:
            print('Hello')


class Point:
    def __init__(self, x_coord=0, y_coord=0):
        self.__x_coord = x_coord
        self.__y_coord = y_coord

    # get x coordinate
    def get_x_coord(self):
        return self.__x_coord

    # set x coordinate
    def set_x_coord(self, x_coord):
        self.__x_coord = x_coord

    # get y coordinate
    def get_y_coord(self):
        return self.__y_coord

    # set y coordinate
    def set_y_coord(self, y_coord):
        self.__y_coord = y_coord

    # get current position
    def get_position(self):
        return self.__x_coord, self.__y_coord

    # change x & y coordinates by p & q
    def move(self, p, q):
        self.__x_coord += p
        self.__y_coord += q

    # overload + operator
    def __add__(self, other):
        return Point(self.__x_coord + other.__x_coord, self.__y_coord + other.__y_coord)

    # overload - operator
    def __sub__(self, other):
        return Point(self.__x_coord - other.__x_coord, self.__y_coord - other.__y_coord)

    # overload < (less than) operator
    def __lt__(self, other):
        return math.sqrt(self.__x_coord ** 2 + self.__y_coord ** 2) < math.sqrt(
            other.__x_coord ** 2 + other.__y_coord ** 2)

    # overload > (greater than) operator
    def __gt__(self, other):
        return math.sqrt(self.__x_coord ** 2 + self.__y_coord ** 2) > math.sqrt(
            other.__x_coord ** 2 + other.__y_coord ** 2)

    # overload <= (less than or equal to) operator
    def __le__(self, other):
        return math.sqrt(self.__x_coord ** 2 + self.__y_coord ** 2) <= math.sqrt(
            other.__x_coord ** 2 + other.__y_coord ** 2)

    # overload >= (greater than or equal to) operator
    def __ge__(self, other):
        return math.sqrt(self.__x_coord ** 2 + self.__y_coord ** 2) >= math.sqrt(
            other.__x_coord ** 2 + other.__y_coord ** 2)

    # overload == (equal to) operator
    def __eq__(self, other):
        return math.sqrt(self.__x_coord ** 2 + self.__y_coord ** 2) == math.sqrt(
            other.__x_coord ** 2 + other.__y_coord ** 2)


def main():
    student = Student('Xuhua Huang', 1879700, 'Electrical Engineering')
    student.say_hello()
    student.say_hello('Lanfeng')

    '''
    Test class Point
    '''
    point1 = Point(2, 4)
    point2 = Point(12, 8)

    print("point1 < point2: ", point1 < point2)
    print("point1 > point2: ", point1 > point2)
    print("point1 <= point2: ", point1 <= point2)
    print("point1 >= point2: ", point1 >= point2)
    print("point1 == point2: ", point1 == point2)


if __name__ == '__main__':
    main()
