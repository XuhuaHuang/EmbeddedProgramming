/*****************************************************************//**
 * \file   smart_pointers.cpp
 * \brief  contains notes on smart pointers in C++
 * Highlight member function in <memory>:
 * 1) make_unique<T>
 * 2) make_shared
 * 3) weak_ptr
 * 
 * \author Xuhua Huang
 * \date   May 2021
 *********************************************************************/

#include <memory>
#include <iostream>

class Entity
{
public:
    Entity() {
        std::cout << "[DFCONST]Creating Entity..." << std::endl;
    }

    ~Entity() {
        std::cout << "[DFDEST]Destroying Entity..." << std::endl;
    }

    void printEntity() {
        std::cout << "[fn]Printing Entity..." << std::endl;
    }
};

int main(void)
{
    /**
     * Create a new scope and verify the output in the terminal.
     * Expecting constructor, destructor get called sequentially.
     * \return 
     */
    { 
        std::unique_ptr<Entity> entity_ptr(new Entity()); // not exception safe 
        // better approach: make_unique<Entity>
        // equivalent to: std::unique_ptr<Entity> entity_ptr = std::make_unique<Entity>();
        entity_ptr->printEntity(); // using pointer as how normally it is used
    } // destructor gets called automatically when pointer goes out of scope

    // share_ptr uses reference count approach to determine when to delete the pointer
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    std::weak_ptr<Entity> weakEntity = sharedEntity; // does not increase reference count

    std::cin.get();
    return 0;
}