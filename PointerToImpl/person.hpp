/**
 * @file person.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-25
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <memory>
#include <string>

namespace pimpl
{

class Person
{
public:
    Person(const std::string& name, int age);
    ~Person();

    std::string name() const;
    void        setName(const std::string& name);

    int  age() const;
    void setAge(int age);

private:
    class PersonImpl;
    std::unique_ptr<PersonImpl> impl_;
};

class Person::PersonImpl
{
public:
    std::string name;
    int         age;
};

Person::Person(const std::string& name, int age)
    : impl_(new PersonImpl{name, age})
{
}

Person::~Person() = default;

std::string Person::name() const
{
    return impl_->name;
}

void Person::setName(const std::string& name)
{
    impl_->name = name;
}

void Person::setName(std::string&& name)
{
    impl_->name = std::move(name);
}

int Person::age() const
{
    return impl_->age;
}

void Person::setAge(int age)
{
    impl_->age = age;
}

} // namespace pimpl

#endif
