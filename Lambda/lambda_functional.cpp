/*****************************************************************//**
 * \file   lambda_functional.cpp
 * \brief  example on using lambda expression with function pointer and
 *         algorithm std::find_if()
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

template<class T>
void printVector(std::vector<T> argVector)
{
    std::cout << "\n[fn]The content of this vector is listed: " << "\n";

    typename std::vector<T>::iterator iter; // keyword 'typename' is required for iterator
    for (iter = argVector.begin(); iter < argVector.end(); iter++)
        std::cout << *iter << "\n"; // dereference the iterator to print content

    std::cout << "[fn]This is the end of the vector." << "\n";
    return;
}

// const std::vector<int>& values - an integer vector passed by reference
// const std::function<void(int)>& func - function pointer, returns void, takes an integer argument
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
    for (int value : values)
        func(value);
}

int main(void)
{
    /* define the size of the vector */
    static const int vectorSize = 10;

    /* create an empty vector */
    std::vector<int> values = {};

    /* initialize random seed */
    srand((unsigned int)time(NULL));

    int randomNum;
    /* generate random number between 1 and 10 and add to vector */
    for (int i = 0; i < vectorSize; i++)
    {
        randomNum = rand() % 10 + 1;
        values.push_back(randomNum);
    }

    // printVector(values); // uncomment this line to see the content of the vector

    /* create a lambda */
    auto print_int_val = [&](int value) {
        std::cout << "Printing with lambda: " << value << "\n";
    };

    /* call ForEach and pass lambda as a function pointer */
    ForEach(values, print_int_val);

    /* std::find_if() */
    auto iter = std::find_if(values.begin(), values.end(),
        [](int value) -> int { return value > 3; }
    );

    std::cout << "\nThe first element that's greater than 3 has a value of: " << *iter << "\n";

    return 0;
}
