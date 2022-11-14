/*****************************************************************//**
 * \file   uncopyable_class.cpp
 * \brief  prevent copying - even with compiler generated
 *         copy-constructor and assignment operator
 *
 *         declare the copy constructor and copy assignment operator
 *         private in a base class and deleberately NOT implement them
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>
#include <string>

class Uncopyable
{
protected:
    // allow construction and destruction of derived class objects
    Uncopyable() {}
    virtual ~Uncopyable() {}

private:
    // compiler sees these function, will attempt to call
    // declared as private, will not be called succesfully
    Uncopyable(const Uncopyable&) {}
    Uncopyable(Uncopyable&&) noexcept {}
    Uncopyable& operator=(const Uncopyable&) {}
    Uncopyable& operator=(Uncopyable&&) noexcept {}
    bool operator==(const Uncopyable&) {}
};

// class that inherits the private part of the base class 'Uncopyable'
class Secret : private Uncopyable
{
private:
    std::string secret = "MY SECRET";
public:
    Secret(const std::string argSecret) : secret(argSecret) {}
    ~Secret() {}
};

int main(void)
{
    Secret mySecret("My secret");
    //Secret yrSecret{ std::move(mySecret) };
    //Secret yrSecret{ mySecret };
    //yrSecret = mySecret;

    return 0;
}
