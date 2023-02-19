/*****************************************************************//**
 * \file   FnPointer.cpp
 * \brief  This file contains the 'main' function.
 * Program execution begins and ends there. Function pointer demo.
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#include <iostream>
#include <functional>
#include <cstdlib>

typedef int(*callback)(int, int);

int add(int a, int b, callback p) {
    return (*p)(a, b);
}

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;
    Entity(const Entity&) = delete;

    // mis-behaving function with the same name
    // for demonstration purpose.
    int add(int a, int b) {
        return a * b;
    }
};

int main(void)
{
    Entity* entity = new Entity();

    std::function<int(int, int)> func;
    func = std::bind(&Entity::add, entity, std::placeholders::_1, std::placeholders::_2);

    callback call_fn = func.target<int(int, int)>();

    if (call_fn == nullptr) {
        std::cout << "nullptr" << "\n";
    }

    std::cout << func(4, 5) << "\n";

    system("pause");
    return 0;
}