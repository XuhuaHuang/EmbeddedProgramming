/*****************************************************************//**
 * \file   array.cpp
 * \brief  templatized array in C++
 *
 * Document highlight: range-based for-loop
 *                     std::array<type, size> = {}; // initialization
 *                     at(index)
 *                     get<index> array/tuple_name
 *                     array/tuple_name[index]
 *
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <array>        // at(index)
#include <tuple>        // get<index> array/tuple_name

// function prototype
void printArray(std::array<int, 20> data);

int main(void)
{
    // initializing the array elements
    std::array<int, 6> data = { 1, 2, 3, 4, 5, 6 };
    std::cout << "\nA 6-element array named \"data\" has been created with elements incrementing from 1 to 6" << "\n";

    // printArray(data); // umcomment this line if you want to use the printArray function

    std::cout << "\nUsing different member function to print..." << "\n";

    // printing array elements using at() 
    std::cout << "\nThe array elements are printed using \"at(index)\" member function: ";
    for (int i = 0; i < 6; i++)
        std::cout << data.at(i) << " ";
    std::cout << "\n";

    // printing array elements using get() 
    std::cout << "\nThe array elements are printed using \"get<index> array/tuple_name\" member function: "
        << std::get<0>(data) << " " << std::get<1>(data) << " "
        << std::get<2>(data) << " " << std::get<3>(data) << " "
        << std::get<4>(data) << " " << std::get<5>(data) << " "
        << "\n";

    // printing array elements using operator[] 
    std::cout << "\nThe array elements are printed using method \"array_name[index]\": ";
    for (int i = 0; i < 6; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";

    std::cout << "\nUsing range-based for loop to print the element of array \"data\": ";
    for (int elem : data)
        std::cout << elem << " ";
    std::cout << "\n";

    return 0;
}

// function to print the array
void printArray(std::array<int, 6> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "\t";
    }
    std::cout << "\n";

    return;
}
