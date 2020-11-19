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
#include "Inheritance_polymorphism.h"

using namespace std;

int main(void) 
{
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    cout << "Sound from class \"Animal\":";
    myAnimal.animalSound();

    cout << "Sound from class \"Pig\":";
    myPig.animalSound(); // animalSoung() function in class Pig has a higher priority than base class
    
    cout << "Sound from class \"Dog\": ";
    myDog.animalSound(); // animalSoung() function in class Dog has a higher priority than base class
    
    return 0;
}
