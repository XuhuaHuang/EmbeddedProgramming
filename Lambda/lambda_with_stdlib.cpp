/**
 * @file lambda_with_stdlib.cpp
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-07-18
 *
 * $ g++ -o lambda_stdlib.exe lambda_with_stdlib.cpp -std=c++2a
 * $ .\lambda_stdlib.exe
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

class Person {
public:
    Person() : _first_name(""), _last_name("") {}
    Person(std::string first_name, std::string last_name) : _first_name(first_name), _last_name(last_name) {}
    std::string firstname() const { return this->_first_name; }
    std::string lastname() const { return this->_last_name; }
    void firstname(const std::string first_name) { this->_first_name = first_name; }
    void lastname(const std::string last_name) { this->_last_name = last_name; }

    void print_to_stdcout() {
        std::cout << this->firstname() << " " << this->lastname() << "\n";
    };

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
        vec_people[i].print_to_stdcout();

    // sort according to the name
    std::sort(
        vec_people.begin(),
        vec_people.end(), // the range of elements to sort
        [](const Person& p1, const Person& p2) {
            return p1.lastname() < p2.lastname() ||
                (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
        }
    );

    for (int i = 0; i < vec_people.size(); i++)
        vec_people[i].print_to_stdcout();

    system("pause");
    return 0;
}