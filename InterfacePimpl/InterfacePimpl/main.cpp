/**
 * @file main.cpp
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Interface Pointer to Implementation.
 *
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Person.h"
#include <iostream> // this will be ignored by the include guard _IO_STREAM_

int main(void) {
    std::string name;
    Date dateOfBirth;
    Address liveAddr;

    // creating an object that implements the `Person` interface
    std::tr1::shared_ptr<Person> ptrPerson(Person::createPerson(name, dateOfBirth, liveAddr));
    // accessing info of such person using const getters
    std::cout << ptrPerson->name()
        << ptrPerson->birthDate()
        << ptrPerson->address();

    return 0;
}
