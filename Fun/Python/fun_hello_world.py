print("Hello World")
first_name = input("\nPlease enter your first name to the right: ")
last_name = input("Please enter your last name to the right: ")
birth_year = input("What year were you born? ")
print("\nYou full name is " + first_name + " " + last_name)

# how to convert a string to integer?
# print("It looks like you are " + age + " years old.")

age = 2020 - int(birth_year)
print(age)

message = f'{first_name} {last_name} wants to be a programmer.'
print(message)

weight_in_lbs = input("\nWhat is your weight in pounds? ")
weight_in_kgs = float(weight_in_lbs) * 0.45
print(weight_in_kgs)
print("Do you roughly weigh that much? Press Y to continue and N to exit. ")
confirm = input("The character is not case sensitive: ")

y_n = bool(confirm)
print(y_n)

# if y_n is True
# How do you write an if statement in Python?

print("\nstring variable \"course\" is defined as \"Python for beginners.\"")
course = 'Python for beginners'
print("Converting the sentence to upper case and print.")
print(course.upper())
print("Converting the sentence to lower case and print.")
print(course.lower())
