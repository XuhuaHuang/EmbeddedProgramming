print("Hello World")
first_name = input("Please enter your first name to the right ")
last_name = input("Please enter your last name to the right ")
birth_year = input("What year were you born? ")
print("You full name is " + first_name + " " + last_name)

# how to convert a string to integer?
# print("It looks like you are " + age + "years old")

age = 2020 - int(birth_year)
print(age)

message = f'{first_name} {last_name} wants to be a programmer.'
print(message)

weight_in_lbs = input("What is your weight in pounds? ")
weight_in_kgs = float(weight_in_lbs) * 0.45
print(weight_in_kgs)
print("Do you roughly weigh that much? Press Y to continue and N to exit. ")
confirm = input("The character is case sensitive ")

y_n = bool(confirm)
print(y_n)

# if y_n is True
# How do you write an if statement in Python?

course = 'Python for beginners'
print(course.upper())
print(course.lower())
