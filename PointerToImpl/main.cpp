/**
 * @file main.cpp
 * @author Xuhua Huang
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * g++ .\main.cpp -o ./piml.exe -std=c++2a
 * ./pimpl.exe
 * 
 * @copyright ueg (c) 2023
 * 
 */

#include "person.hpp"

int main() {
    pimpl::Person p("Alice", 30);
    std::cout << p.name() << ", " << p.age() << std::endl;

    p.setName("Bob");
    p.setAge(40);
    std::cout << p.name() << ", " << p.age() << std::endl;

    return 0;
}
