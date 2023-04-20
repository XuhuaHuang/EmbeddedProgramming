/**
 * @file lambda_with_stdlib.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2022-07-18
 *
 * $ g++ -o lambda_stdlib.exe lambda_with_stdlib.cpp -std=c++2a
 * $ .\lambda_stdlib.exe
 *
 * $ cl .\lambda_with_stdlib.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
 * .\lambda_with_stdlib.exe
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>



struct Person
{
public:
    Person() : _first_name(""), _last_name("") {}
    Person(const std::string& first_name, const std::string& last_name)
        : _first_name(first_name)
        , _last_name(last_name) {}

    // mutator and accessor
    // using the nature of function overloading
    std::string firstname() const { return this->_first_name; }
    std::string lastname() const { return this->_last_name; }
    void firstname(const std::string first_name) { this->_first_name = first_name; }
    void lastname(const std::string last_name) { this->_last_name = last_name; }

    void print_to_stdcout() {
        std::cout << this->firstname() << " " << this->lastname() << "\n";
    };

    // copy constructor
    Person(const Person& rhs) {
        this->firstname(rhs.firstname());
        this->lastname(rhs.lastname());
    }

    // move constructor
    Person(Person&& rhs) noexcept {
        this->firstname(std::move(rhs.firstname()));
        this->lastname(std::move(rhs.lastname()));
    }

    // copy assignment operator
    Person operator=(const Person& rhs) {
        return Person(rhs.firstname(), rhs.lastname());
    }

    // move assignment operator
    Person operator=(Person&& rhs) noexcept {
        return Person(std::move(rhs.firstname()), std::move(rhs.lastname()));
    }

    inline bool operator==(const Person& rhs) const {
        return (this->firstname() == rhs.firstname()) && (this->lastname() == rhs.lastname());
    }

    virtual ~Person() = default;

private:
    std::string _first_name;
    std::string _last_name;
};

int main(void) {
    // initialize an empty array
    std::vector<Person> vec_people {};

    Person me = Person();
    me.firstname("Xuhua");
    me.lastname("Huang");
    Person partner = Person("Lanfeng", "Jin");

    vec_people.push_back(partner);
    vec_people.push_back(me);

    for (int i = 0; i < vec_people.size(); i++)
    {
        vec_people[i].print_to_stdcout();
    }

    // sort according to the name
    std::sort(
        vec_people.begin(),
        vec_people.end(), // the range of elements to sort
        [](const Person& p1, const Person& p2) {
            return p1.lastname() < p2.lastname()
                || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
        }
    );

    for (int i = 0; i < vec_people.size(); i++)
    {
        vec_people[i].print_to_stdcout();
    }

    return 0;
