/*****************************************************************//**
 * \file   move_assignment.cpp
 * \brief  std::move use case demonstration and Move Assignment Operator
 * 
 * g++ -c move.cpp -o move.exe -std=c++20
 * ./move
 * 
 * \author Xuhua Huang
 * \date   April 2022
 *********************************************************************/

#include <iostream>
#include <string>

class Entity {
public:
    Entity() : m_Name("") {}
    Entity(const std::string& name) : m_Name(name) {}
    Entity(std::string&& name) : m_Name(std::move(name)) {}

    void PrintName() {
      std::cout << "Entity::PrintName(): m_Name = " << this->m_Name << "\n";
    }
private:
    std::string m_Name;
};

int main() {
    Entity entity{ "Xuhua Huang" };
    entity.PrintName();

    std::string source = "Hello, world";
    // constructing a copy of source
    // then assign temporary variable to destination
    std::string destination1 = source;

    // copy constructor with list initialization
    std::string destination2 { source };

    // implcitly calls move constructor
    // source is converted to a pure rvalue (i.e. temporary variable)
    std::string destination3 { static_cast<std::string&&>(source) };
    // equivalent to the following
    std::string destination4 = std::move(source);

    std::cin.get();
    return 0;
}
