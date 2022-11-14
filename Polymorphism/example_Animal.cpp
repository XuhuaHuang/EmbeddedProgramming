/*
 * Type: notes
 * Topic: Inheritance polymorphism
 *
 * Content: if derived class has the same function name, return type and parameter
 *          when object calls the fuction, current class function is called
 *          i.e. prioritized
 *
 * Created on: Nov 06, 2020
 */

#include <iostream>
#include <string>
#include "example_Animal.hpp"

int main(void)
{
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    std::cout << "Sound from class \"Animal\":";
    myAnimal.animalSound();

    std::cout << "Sound from class \"Pig\":";
    myPig.animalSound(); // animalSound() function in class Pig has a higher priority than base class

    std::cout << "Sound from class \"Dog\": ";
    myDog.animalSound(); // animalSound() function in class Dog has a higher priority than base class

    return 0;
}
