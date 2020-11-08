# This file contains notes and examples for functions in Python
# Topic: function - lambda(one line function), definition and calling and
# Author: Xuhua Huang
# Created: Nov 07, 2020
# Last updated: Nov 07, 2020

# include function from math library
from math import sqrt

# 1.1
# lambda
# takes any number of arguments, but can only have one expression
# result of the expression is automatically returned
# [function name] lambda arguments : expression


x = lambda a: a + 20
print(x(5))
# 'x' specifies the lambda expression being called - function name
# a = 5, return (5 + 20)

y = lambda b: b * b
print(y(7))
# b = 7, return (7 * 7)

hypotenuse = lambda a, b: sqrt(a * a + b * b)
print(hypotenuse(3, 4))


# a = 3, b = 4, hypotenuse = 5

# 2.1
# function definition
# syntax: def function_name(parameters):
# no significant 'return variable' line
# when calling: function_name(arguments)
def hypotenuse_function(a, b):
    return sqrt(a * a + b * b)


# calling above function
hypotenuse2 = hypotenuse_function(6, 8)
print(hypotenuse2)


# 2.2
# default parameter value in a function
def coming_from(country="China"):
    print("\nArgument default to \"China\"")
    if country != "China":
        print("Overloaded to: " + country + "\n")  # string concatenation


coming_from()
coming_from("Canada")  # should see an extra line


# 2.3 pass statement
def pass_function():
    pass


pass_function()


# 2.4
# recursion - a function calls itself
# can be avoided with proper manipulation with loops
#
# logic for the following function 'multi_recursion'
# calling with 5: 5 + 4 + 3 + 2 + 1 = 15
# considered complete iteration
# subsequent calling listed as following:
# calling with 4: 4 + 3 + 2 + 1 = 10
# calling with 3: 3 + 2 + 1 = 6
# calling with 2: 2 + 1 = 3
# calling with 1: 1 + 0 = 1
def multi_recursion(k):
    if k > 0:
        result = k + multi_recursion(k - 1)
        print(result)
    else:
        result = 0
    return result


# multi_recursion(5)
print(f"\nFinal calling result with argument 5: {multi_recursion(5)}.")


# another recursion example
# adding 1 - 100 with recursion function
# 100 + 99 + 98 + ... + 3 + 2 + 1
def summation(most_significant):
    if most_significant == 1:
        sum = 1
    elif most_significant > 1:
        sum = most_significant + summation(most_significant - 1)
    return sum


print(f"\nThe sum of integer from 1 to 100 is: {summation(100)}.")
