/*****************************************************************//**
 * \file   Person.h
 * \brief  Contains pure virtual functions for an interface `Person`
 *
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

/* Use forward declaration to provide class interfaces. */
/* Do NOT need to recompile unless the class name changes. */
class Date {};
class Address {};

/* Person interface. */
class Person
{
public:
    virtual ~Person() {}

    /**
     * It is impossible to instantiate an instance for this interface;
     * however, its child classes have to have access to a so-called `factory` function.
     */
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
    virtual std::string address() const = 0;

    /* Factory function to be used by child classes. */
    /* Declared static for syntax `Person::createPerson()`. */
    static std::shared_ptr<Person> createPerson(
        const std::string& name,
        const Date& birthday,
        const Address& addr
    ) { return std::make_shared<Person>(); }

private:
    /**
     * Private constructor and copy constructor.
     */
    Person() {}
    Person(const Person&) {}

    /* Data attributes for Person */
    std::string _name;
    Date _birthday;
    Address _address;
};

/** REMEMBER: derive class write factory functions
 *
 * Use case for the factory/virtual constructor for interface Person:
 * std::string name;
 * Date dateOfBirth;
 * Address liveAddr;
 *
 * // creating an object that implements the `Person` interface
 * std::tr1::shared_ptr<Person> ptrPerson(Person::createPerson(name, dateOfBirth, liveAddr));
 * // accessing info of such person using const getters
 * std::cout << ptrPerson->name()
 *           << ptrPerson->birthDate()
 *           << ptrPerson->address();
 */
#endif