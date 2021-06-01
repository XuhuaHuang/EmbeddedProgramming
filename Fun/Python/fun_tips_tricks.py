# Topic: Tips and tricks when programming in Python
# Author: Xuhua Huang
#
# Last updated: May  27, 2021
# Created on: May 27, 2021

# in line multiple assignment
from typing import List, Any, Union

x, y = 1, 1
origin = 0, 0

# print colored output
# may be only available in console
print("\033[91mHello, \033[94mworld\033[96m")  # red, blue, the rest of the output in green

# raise a number to power
print(5 ** 2)  # 25

# Banker's rounding
# rounding up/down to the closest even number when rounding .5 values
print(round(10.5))  # expecting 10
print(round(11.5))  # expecting 12

# underscores in a very large number
investment: int = 999_999_999
print(investment)

# open link with module 'webbrowser'
# import webbrowser
# webbrowser.open('https://www.google.ca')

# concatenation strings without '+' operator
message = "Hello" ", this is a message"
print(message)

# [10] multiline string
# escape sequence \ to ignore newline. No spaces after
print('''This is a really long message that I split up over \
multiple lines for convenience sake.
This line is affected and concatenated to the line above.''')

# reverse a list/string with slicing
important_data = [1, 2, 3, 4, 5]
print(important_data[::-1])  # important_data[0:0 :-1] from start to end, starting from the right hand side
# upper line does not modify the original data
important_data.reverse()
print(important_data)

# look for sub-string
# with 'in' operator
if "E" in "IDEA Editor":
    print("IDEA Editor".index("E"))
# with 'find()' method
"IDEA Editor".find("E")  # 2; indexing starts with number 0
"IDEA Editor".find("Non existing")

# get address with id() method
data_dict = {"Xuhua Huang": 20}
print(id(data_dict))

# aliases
# using two variables pointing to the same data
another_dict = data_dict
print("Original data id: " + str(id(data_dict)))  # call str() method to concatenate
print("Alias data id: " + str(id(another_dict)))

another_dict["API_User"] = 25
print("Modified alias data: " + another_dict.__str__())  # __str__() returns the string representation
print("Modified alias data id: " + str(id(another_dict)))


# replace list v.s. replace list content
def replace_list(data):
    data = ["new"]


def replace_list_content(data):
    data[:] = ["new"]


languages = ['C', 'C++', 'Java', 'Rust', 'Python']
print(languages)
replace_list(languages)
print(languages)  # same as original
replace_list_content(languages)
print(languages)  # 'new'

# copy a list with slicing
learning = languages[:]  # from start to end
print("Original list ID: " + str(id(languages)) + " " + \
      "Copy list ID: " + str(id(learning)))

# copy a list with method
learning = languages.copy()
print("With 'list_name.copy()' method")
print("Original list ID: " + str(id(languages)) + " " + \
      "Copy list ID: " + str(id(learning)))

# deepcopy
from copy import deepcopy

tech = ['C', 'C++', 'Java', ['html', 'css']]
learning = deepcopy(tech)
print(id(tech) == id(learning))  # false
print(id(tech[-1]) == id(learning[-1]))  # false
# if id(tech) == id(learning):
#     print("Deepcopy keeps the same ID")

# concatenate list
beginning = [1, 2, 3]
end = [4, 5, 6]
print(beginning + end)

# globals() method
# returns a dictionary of the current 'global' symbol table
print("Current global exposures: " + str(globals()))

# inline assignment for list
squares = [i ** 2 for i in range(10)]
print(squares)

# sort data
unordered_list = [2, 3, 5, 1, 4, 8, 6, 7]
sorted_list = sorted(unordered_list, reverse=True)
print(sorted_list)

# set() returns an unique element from a list by removing duplicated elements
my_set = set(sorted_list)  # does not remove anything since no duplicated element

# count number of elements with 'Counter' module
from collections import Counter

random_int_list = [10, 10, 10, 5, 5, 2, 9, 9, 9, 9, 9]
print(Counter(random_int_list))  # automatically sorted with descending order of appeared times
list_counter = Counter(random_int_list)
print(list_counter.most_common(1))  # returns a list of tuples

# concatenate strings with .join() method
list_of_string = ["Hello", "World", "from", "Python"]
my_string = " ".join(list_of_string)
print(my_string)

# ternary conditional operator
# typical usage:
experience_in_years = 20
if experience_in_years >= 15:
    name = "Admin"
else:
    name = "Developer"

print(name)  # admin

experience_in_years = 30
name = "Admin" if experience_in_years >= 35 else "Developer"
print(name)  # Developer

# using else in a loop
pets = ['dog', 'dog', 'cat', 'bird', 'chicken', 'dog']
if 'cat' in pets:
    print("cat found in the list 'pets'")  # option 1

# option 2
cat_found = False
for pet in pets:
    print(pet, end=" ")  # print with a spacer; do something with each element if needed
    if pet == 'cat':
        cat_found = True  # could count elements or perform other operations
        break

if cat_found:  # cat_found == True
    print("cat found in the list 'pets'")  # option 2

pets.remove('cat')
for pet in pets:
    print(pet, end=" ")
    if pet == 'cat':
        break

else:  # no break -- option 3
    print()
    print("no cat found in the list 'pets'")


# unpack operator
def move_to_position(x: int, y: int, z: int):
    print(f"[fn]move_to_position\nMoving cursor to ({x}, {y}, {z})")


pos = [5, 10, 15]
move_to_position(*pos)
print(pos)

# complex conditional
experience_in_years = 20
age = 40

admin_condition = [
    age >= 35,
    experience_in_years >= 20
]

if any(admin_condition):  # any => 'or' operator
    # if all(admin_condition):  # all => 'and' operator
    print("You are now an admin")  # expecting admin output

# .split() method
# split a string to multiple variables
full_name = "Xuhua Huang"
first_name, last_name = full_name.split()
print(f"First Name: {first_name} Last Name: {last_name}")

data = "1 2 3"
data = [int(d) for d in data.split()]
print(data)
# similarly, get data from console separated with spaces
first_name, last_name = input("Please enter your first name and last name separated by a space: ").split()
print(f"You entered:\nFirst Name: {first_name} Last Name: {last_name}")

# flatten a 2D list
pairs = [[5, 10], [15, 20], [25, 30, 35, 40]]

flat = []
'''
for pair in pairs:
    for item in pair:
        flat.append(item)

print(flat)
'''

flat_list = [item for pair in pairs for item in pair]
print(flat_list)
# notice important sections:
# for pair in pairs
# for item in pair
# retrieve pair first, then item in each pair

# use a list to contain conditions to compare
current_weather = 'rainy'
if current_weather in ['rainy', 'snowy', 'stormy']:
    print("Event cancelled")
    event_cancelled = True

# do-while loop equivalent in Python
'''
while True:
    print("Do what you want")
    # determine condition
    # check condition
    if condition == True:
        break
'''
while True:
    print('''
    1. Press key 1 to play the game
    2. Press key 2 to resume from where you left
    3. Press key 3 to see high scores record
    4. Press key 4 to quit the game''')
    if input() == '4':
        break


# invoke function after current function finishes executing
def done():
    print("Done")


# sleep() with time module
import time


def do_things(func):
    print("Doing things...")
    time.sleep(8)
    func()  # invoke callback function


# invoke enumerate() on lists
# previously, pets = ['dog', 'dog', 'cat', 'bird', 'chicken', 'dog']
for index, pet in enumerate(pets):
    print(f"Index of the pet: {index} Type: {pet}")


# updated on May 31, 2021
# wrapping a primitive to change within function
class Container:
    def __init__(self, data):
        self.data = data


def calculate(input):
    input.data **= 5


container = Container(5)  # initialize a container of int 5
calculate(container)  # 5 ** 5
print(container.data)

# compare identity with 'is'
# compare whether two are the same objects, not values
c1 = Container(5)
c2 = Container(5)
print(c1 == c2)  # True
print(id(c1), id(c2))
# print(id(c1) == id(c2))  # False
print(c1 is c2)  # better approach; False


# add a method dynamically
def __eq__(self, other):
    return self.data == other.data


Container.__eq__ = __eq__

print(Container.__eq__)

# infinite number
import math

print(math.inf)
inf = math.inf
print(inf, inf - 1)


# custom type iterator with iter
class Node:
    def __init__(self, data, next_node=None):
        self.data = data
        self.next = next_node


class LinkedList:
    def __init__(self, start):
        self.start = start

    def __iter__(self):
        node = self.start
        while node:
            yield node
            node = node.next


linked_list = LinkedList(Node(5, Node(10, Node(15, Node(20)))))
for node in linked_list:
    print(node.data)

# combine two lists into a list of lists
names = ['Xuhua', 'Lanfeng']
score = [100, 150]

combined_names_score = list(zip(names, score))
print(combined_names_score)

import pandas as pd

data_dict = dict(combined_names_score)
data_frame = pd.DataFrame(data_dict)
print(data_frame)
