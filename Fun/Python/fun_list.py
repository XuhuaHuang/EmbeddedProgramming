# Examples on lists
fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']
# Created a list named fruit

# list_name.count(variable)
print(f'The times element \'apple\' shows up for {fruits.count("apple")} times.')
print(f'The times element \'tangerine\' shows up for {fruits.count("tangerine")} times.')
print(f'The times element \'banana\' shows up for {fruits.count("banana")} times.')

print("\nThe reversed list named \'fruits\' is now: ")
fruits.reverse()  # list_name.reverse only reverses the index
print(fruits)

print("\nAppending grape...")
fruits.append('grape')
print(fruits)
print("\'grape\' is appended. Sorting list...")
fruits.sort()
print("Sorted.")
print(fruits)

print("\nlist_name.pop() function grabs the last element in the list.")
print(fruits.pop())

# List comprehensions
print("\nCreating a list of integers 0 - 9 called \'squares\'")
squares = []
# Equivalent: squares = list(map(lambda x: x**2, range(10)))
#                       squares = [x**2 for x in range(10)]
for x in range(10):  # for (int i =0; i < 10; i++)
    squares.append(x)
    print(f'Recently added element: {squares[x]}')
print("\nSquaring each elemnt in the list...")
for x in range(10):
    squares.append((squares[x])**2)
    print(f'Item squared: {squares[x]} .')

# more list comprehension
print("\nCreating a 2D dimension coordinate list...")
cords = []
for x in [1,2,3]:
    for y in [3,1,4]:
        if x != y:
            cords.append((x,y))
# Equivalent: [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
# [(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
print(cords)

from math import pi
print("\nRounding Pie with increment in digits")
print([str(round(pi, i)) for i in range(1, 6)])

print("\nFlattening a list...")
vec = [[1,2,3], [4,5,6], [7,8,9]]
print(f'Original list \'vec\' is: {vec}')
# print([num for elem in vec for num in elem])

print("\nRetreiving element with nested for-loops")
for elem in vec:
    for num in elem:
        print(f'Recently retrieved element: {num}')


print("To be continued...")
print("Next: Nested List Comprehensions")
