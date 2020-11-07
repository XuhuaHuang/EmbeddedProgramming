# single line string
# print(variable name)
greeting = "Hello, world!"
print(greeting)

# formatted string - used to print sentences with variables
print("Printing a formatted string...")
print(f"The string variable \"greeting\" is written as: {greeting}")

# multiple lines string enclosed with triple single/double quotes
blockString = '''
This is a block string.
Syntax: variable name = \'\'\'
        block
        string
        enclosed by triple single/double quotation marks
\'\'\'
'''
print(blockString)

# determine the length of a string with len(string name) function
# print it out with formatted string
print(f"The length of printed block string is: {len(blockString)}.")

# string are arrays and can be sliced - called slicing a string
print("\nSlicing and printing 0 to 5 element in the greeting string")
print(greeting[0:5])  # print 'Hello'
print("Slicing and printing -6 to -1 element in the greeting string")
print(greeting[-6:-1])  # print 'world'

# string concatenation
# string c = string a + string b
word1 = "hello"
print(f"\nVariable \"word1\" is initialized to: {word1}.")
word2 = "world"
print(f"Variable \"word2\" is initialized to: {word2}.")

print("\nConcatenating and printing \"word1\" and \"word2\"")
sentence = word1 + word2  # sentence = "helloworld"
print(sentence)
print("Adding an extra space between hello and world: ")
sentenceImproved = word1 + " " + word2
print(sentenceImproved)

# various string class method
# variable.upper() and variable.lower()
print(f"\nChanging variable \"word1\" to upper case: {word1.upper()}.")
print(f"Overwriting variable \"word1\" to lower case: {word1.lower()}.")

# format() method
# used to insert numbers into strings
print("\nUsing format() method to insert other variables")
name = input("Please enter your name: ")
age = input("Please enter your age: ")
result = "My name is {}, and I am {} years old."
print(f"Printing with \"format()\" method: {result.format(name, age)}")  # format string and format() method

# other string method:
# Method
#   - Description
#
# capitalize()
#   - Converts the first character to upper case
# casefold()
#   - Converts string into lower case
# center()
#   - Returns a centered string
# count()
#   - Returns the number of times a specified value occurs in a string
# encode()
#   - Returns an encoded version of the string
# find()
#   - Searches the string for a specified value and returns the position of where it was found
# format()
#   - Formats specified values in a string
# index()
#   - Searches the string for a specified value and returns the position of where it was found
#
# isalnum()
#   - Returns True if all characters in the string are alphanumeric
# isalpha()
#   - Returns True if all characters in the string are in the alphabet
# isdecimal()
#   - Returns True if all characters in the string are decimals
# isdigit()
#   - Returns True if all characters in the string are digits
# isidentifier()
#   - Returns True if the string is an identifier
# islower()
#   - Returns True if all characters in the string are lower case
# isnumeric()
#   - Returns True if all characters in the string are numeric
# isprintable()
#   - Returns True if all characters in the string are printable
# isspace()
#   - Returns True if all characters in the string are whitespaces
# istitle()
#   - Returns True if the string follows the rules of a title
# isupper()
#   - Returns True if all characters in the string are upper case
#
# lower()
#   - Converts a string into lower case
# upper()
#   - Converts a string into upper case
# lstrip()
#   - Returns a left trim version of the string
# replace()
#   - Returns a string where a specified value is replaced with a specified value
# split()
#   - Splits the string at the specified separator, and returns a list
# startswith()
#   - Returns true if the string starts with the specified value
# strip()
#   - Returns a trimmed version of the string
# upper()
#   - Converts a string into upper case
# end
