#ifndef _IOSTREAM_
#include <iostream>
#endif

// Base class
class Animal
{
public:
    void animalSound()
    {
        std::cout << "The animal makes a sound." << "\n";
    }
};

// Derived class
class Pig : public Animal // inheritting from base class 'Animal'
{
public:
    void animalSound()
    {
        std::cout << "The pig says: wee wee." << "\n";
    }
};

// Derived class
class Dog : public Animal // inheritting from base class 'Animal'
{
public:
    void animalSound()
    {
        std::cout << "The dog says: bow wow." << "\n";
    }
};
