/*****************************************************************//**
 * \file   VirtualFunctions.cpp
 * \brief  Test question on HackerRank platform.
 * https://www.hackerrank.com/challenges/virtual-functions/problem
 * Passes all test cases and the code is submitted.
 * 
 * Command used to compile:
 * $ g++ -o virtual_fn.exe .\VirtualFunctions.cpp -std=c++11
 * $ .\virtual_fn.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Person
{
public:
    std::string name;
    int age;

    virtual void getdata(void) {
        std::cin >> this->name >> this->age;
    }

    virtual void putdata(void) {
        std::cout << this->name << " " << this->age;
    }
};

class Professor : public Person
{
public:
    int publications;
    int cur_id;

    static int count;

    Professor() {
        count++;
        this->cur_id = count;
    }

    void getdata(void) override {
        Person::getdata();
        std::cin >> this->publications;
    }

    void putdata(void) override {
        Person::putdata();
        std::cout << " " << this->publications << " " << this->cur_id << std::endl;
    }
};

int Professor::count = 0;

class Student : public Person
{
public:
    int marks[7]; // trailing "\n" character
    int cur_id;
    int sum;

    static int count;

    Student() {
        count++;
        this->cur_id = count;
        sum = 0;
    }

    void getdata(void) override {
        Person::getdata();
        for (int i = 0; i < 6; ++i) {
            std::cin >> this->marks[i];
            this->sum += this->marks[i];
        }
    }

    void putdata(void) override {
        Person::putdata();
        std::cout << " " << this->sum << " " << this->cur_id << std::endl;
    }
};

int Student::count = 0;

int main() {

    int n, val;
    std::cin >> n; // The number of objects that is going to be created.
    // Person* per[n];
    std::vector<Person*> per; // change from a C-style array to a modern vector
    per.resize(n);

    for (int i = 0; i < n; i++) {

        std::cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor();

        }
        else per[i] = new Student(); // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}