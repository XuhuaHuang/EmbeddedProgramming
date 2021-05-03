class Animal:
    def __init__(self, name, legs):
        self.name = name
        self.legs = legs

    def get_legs(self):
        return "{0} has {1} legs".format(self.name, self.legs)

    def says(self):
        return "I am an unknown animal"


class Dog(Animal):  # Dog inherits from Animal here (all methods as well)
    def says(self):  # Called instead of Animal says method
        return "I am a dog named {0}".format(self.name)

    def something_dogs_do(self):
        return "Be loyal"


def main():
    formless = Animal("Animal", 0)
    rover = Dog("Rover", 4)  # Calls initialization method from animal
    # Calls animal say method
    print(formless.says())  # "I am an unknown animal"
    # Calls Dog says method
    print(rover.says())  # "I am a dog named Rover"
    print(rover.something_dogs_do())  # Be royal
    print(rover.get_legs())  # Calls get_legs method from animal class


main()