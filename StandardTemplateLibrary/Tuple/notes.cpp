/*****************************************************************//**
 * \file   notes on tuple
 * \brief
 *
 * tuple<type, type> tuple_name {value, value}; // initialization
 * std::get<index>(tuple_name);
 * auto tuple_name = std::make_tuple();
 * std::tie(std::ignore, variable_name) = tuple_name
 * std::tuple_size<decltype(tuple_name)>::value
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>    // std::string
#include <tuple>     // std::tuple, std::get, std::tie, std::ignore

int main(void)
{
    // creat a tuplw with initialization and access element
    std::tuple<int, int> tuple1{ -1, 1 };
    // tuple<type, type> tuple_name {value, value};
    // std::get<index>(tuple_name)
    std::cout << "\nA tuple named \"tuple1\" is created with two integers element." << "\n"
        << "Accessing element in tuple \"tuple1\"..." << "\n"
        << "First element: " << std::get<0>(tuple1) << "\n"
        << "Second element: " << std::get<1>(tuple1) << "\n"
        << "\n\"tuple1\" has "
        << std::tuple_size<decltype(tuple1)>::value << " elements: ";

    // retrieve the print the elements in the terminal
    std::tuple_element<0, decltype(tuple1)>::type first = std::get<0>(tuple1);
    std::tuple_element<1, decltype(tuple1)>::type second = std::get<1>(tuple1);
    std::cout << first << " and " << second << "\n";

    std::cout << "\nChanging element indexed 0 to -2..." << "\n";
    std::get<0>(tuple1) = -2; // assign new value
    std::cout << "The new assigned value is: " << std::get<0>(tuple1) << "\n";

    // initialize tuple with keyword 'auto'
    auto tuple2 = std::make_tuple("tuple2", 1024, 3.14, 'A'); // equivalent to: 
    // std::tuple<std::string, int, double, char> tuple2{ "tuple2", 1024, 3.14, 'A' };

    std::string tupleName; int binaryHundred; double pie; char upperA;
    // another association method with make_tuple()
    // tie(tupleName, binaryHundred, pie, upperA) = make_tuple("tuple2", 1024, 3.14, 'A');

    std::tie(std::ignore, std::ignore, pie, upperA) = tuple2;
    // unpack elements in tuple2 with std::ignore
    // and associate desired elements to declared variable

    std::cout << "\n\"tuple2\" is now unpacked with variable \"double pie\" and \"char upperA\"." << "\n"
        << "Variable \"pie\" is tied to: " << pie << "\n"
        << "Variable \"upperA\" is tied to: " << upperA << "\n"
        << "\nAssociating the other two elements with tie()..." << "\n";

    std::tie(tupleName, binaryHundred, std::ignore, std::ignore) = tuple2;

    std::cout << "Done association." << "\n"
        << "Variable \"tupleName\" is tied to: " << tupleName << "\n"
        << "Variable \"binaryHundred\" is tied to: " << binaryHundred << "\n";

    return 0;
}
