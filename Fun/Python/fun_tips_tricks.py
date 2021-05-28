# Topic: Tips and tricks when programming in Python
# Author: Xuhua Huang
#
# Last updated: May  27, 2021
# Created on: May 27, 2021
#

# in line multiple assignment
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
    data[:] = ['new']


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

list = [10, 10, 10, 5, 5, 2, 9, 9, 9, 9, 9]
print(Counter(list))  # automatically sorted with descending order of appeared times
list_counter = Counter(list)
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
