/*****************************************************************//**
 * \file   stringNotes.cpp
 * \brief  notes on strings in C++
 *
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include <iostream>
#include <string>

int main(void)
{
    std::string theBird; // declare a variable of data type string
    theBird = "Blue-jay"; // initialize the string variable theBird
    std::cout << theBird << "\n";
    std::string action = "fly";
    std::string sentence = theBird + " can " + action; // concatenate in string
    std::cout << sentence << "\n";


    std::string str;
    std::cout << "Enter a  sentence: ";
    getline(std::cin, str); // use the function std::cin and store it in the object str
    //std::cin.ignore(); // ignore the \n characters;
    std::cout << str << "\n";


    std::string name1 = "Bob";
    std::string name2 = "Alex";

    if (name1 < name2) // check alphabetical order
        std::cout << "Bob is before Alex." << "\n";
    else
        std::cout << "Alex is before Bob." << "\n";


    std::string glue = "sticky";
    std::cout << glue << "\n";
    glue.erase(4, 2); // erase function in the string class
    // start erasing at the index 4 and erase 2 characters
    std::cout << "The string after erasing is: " << glue << "\n";


    size_t x = glue.find('i', 0); // return the index of the character i, starting at position  k0
    // find function only looks for one character and finds the first character encountered
    // size_t is the string class equivalent of int
    std::cout << "The character \"i\" is found at position: " << x << "\n";


    std::string hello = "hello";
    size_t y = hello.find('l', 3); // trying to find the letter l starting at position 3
    if (y == std::string::npos) // std::string no position
        std::cout << "The letter \"l\" is not found in string hello." << "\n";
    else
        std::cout << "The letter \"l\" is found at position " << y << "\n";


    // iterator
    std::string tree = "deciduous";
    std::string::iterator iterstr; // pointer

    for (iterstr = tree.begin(); iterstr < tree.end(); iterstr++)
    {
        std::cout << *iterstr;
    }

    return 0;
}
