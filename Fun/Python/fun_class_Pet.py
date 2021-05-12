# Topic: class in python
# Author: Xuhua Huang
# Last updated: Nov 08, 2020
# Created on: Nov 08, 2020
# 
# no private and public specifier
# no need for set and get function
# 
# __init__ function
# 
# self parameter - current instance of class
#                - used to access variables belong to current class
#                - has to be the first parameter of any functions in the class
#                - self can be renamed to other object names


class Pet:
    name = ""
    age = 0

    # __init__ with double underscore
    # acts like a overloaded constructor
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # not necessary to have set and get function
    def set_name(self, user_name):
        self.name = user_name

    def get_name(self):
        return self.name

    def set_age(self, user_age):
        self.age = user_age

    def get_age(self):
        return self.age

    # other function
    def print_pet(self):
        print(f"Your pet of name {self.name} is {self.age} years old.")


def main():
    print("An object of class \"Pet\" is created named \"myPet\", aged 5.")
    # note: syntax of creating an object is different
    myPet = Pet("pet name", 5)  # creating object, name = pet name, age = 5

    print("\nPrinting variables inside of \"Pet\" class with get() functions: ")
    print(myPet.get_name())
    print(myPet.get_age())

    print("\nVariables inside of \"Pet\" class can be accessed without get() functions in Python: ")
    print(f"Accessing variable \"name\" without get() function: {myPet.name}.")
    print(f"Accessing variable \"age\" without get() function: {myPet.age}.")

    print("\nWith print function inside of \"Pet\" class:")
    myPet.print_pet()

    # change properties of an object
    print('''
    \nChanging properties of object \"myPet\":
    name changed to \"new name\"
    age changed to 8
    Properties will be verified with \"object.print() function
    ''')
    myPet.name = "new name"
    myPet.age = 8
    myPet.print_pet()

    print("Deleting object \"myPet\"")
    del myPet  # object is deleted
    print("Deleted.")


main()
