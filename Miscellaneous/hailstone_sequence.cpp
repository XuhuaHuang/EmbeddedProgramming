// clang-format off
/*****************************************************************//**
 * \file   fun_hailstone_sequence.cpp
 * \brief  Generate a Hailstone sequence with C++
 *         print vector with template function
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/
// clang-format on

#include <iostream>
#include <vector>

#ifndef SIZE
#define SIZE 2000
#endif

// funtion used to print vector with template
template<typename T>
void printVector(std::vector<T> vector)
{
    std::cout << "\n[fn][printVector]The content of received vector is listed: "
              << "\n";

    typename std::vector<T>::iterator iter;
    for (iter = vector.begin(); iter < vector.end(); iter++)
    {
        std::cout << *iter << "\n";
    }

    std::cout << "[fn][printVector]This is the end of the vector."
              << "\n";

    return;
}

int main(void)
{
    int              element;
    int              count    = 1;
    std::vector<int> sequence = {};

    std::cout << "Reminder: the first element of the sequence should be greater than 1."
              << "\n"
              << "Please enter the first element of the Hailstone sequence: ";
    std::cin >> element;

    if (element > 1)
    {
        std::cout << "\n"
                  << "Generating Hailstone sequence..."
                  << "\n"
                  << "\n";

        do
        {
            (element % 2) ? element = 3 * element + 1 : element /= 2;
            // output current count and value
            std::cout << "Current count: " << count << ", Element: " << element << "\n";
            // increment count
            count++;
            // add new elemnt to vector<int> sequence
            sequence.push_back(element);
        } while (element > 1 && count <= SIZE);

        std::cout << "\nFinished generating sequence."
                  << "\n"
                  << "Steps used to generate sequence: " << count - 1 << "\n";
    }
    else if (element == 1)
    {
        std::cout << "Error! { 1 } is already a Hailstone sequence!"
                  << "\n"
                  << "Please try again!"
                  << "\n";
    }
    else
    {
        std::cout << "Unable to recognize input. Fatal error."
                  << "\n"
                  << "Aborting..."
                  << "\n";
    }

    std::cout << "\nCalling funtion \"printVector(vector T)\""
              << "\n";
    printVector(sequence);

    return 0;
}
