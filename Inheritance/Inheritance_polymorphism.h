#include <iostream>

using namespace std;

class Animal
{
public:
    void animalSound()
    {
        cout << "The animal makes a sound." << endl;
    }
};

// Derived class
class Pig : public Animal // inheritting from base class 'Animal'
{
public:
    void animalSound()
    {
        cout << "The pig says: wee wee." << endl;
    }
};

// Derived class
class Dog : public Animal // inheritting from base class 'Animal'
{
public:
    void animalSound()
    {
        cout << "The dog says: bow wow." << endl;
    }
};
