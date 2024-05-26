// clang-format off
/*****************************************************************//**
 * \file   lab_with_template.cpp
 * \brief  using template function for various vectors
 *
 * \author Xuhua Huang
 * \date   November 2020
 * \last modified: March 2021
 *********************************************************************/
// clang-format on

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

void squareAndPrint(int x)
{
    std::cout << "Squared: " << (x * x) << "\n";
    return;
}

template<class T>
void printVector(const std::vector<T>& argVector)
{
    std::cout << "\n[fn]The content of this vector is listed: "
              << "\n";

    typename std::vector<T>::const_iterator iter; // keyword 'typename' is required for iterator
    for (iter = argVector.begin(); iter < argVector.end(); iter++)
        std::cout << *iter << "\n"; // dereference the iterator to print content

    std::cout << "[fn]This is the end of the vector."
              << "\n";
    return;
}

template<class T>
void palindrome(const std::vector<T>& vectorT)
{
    printVector<T>(vectorT); // print the original/received vector

    std::vector<T> vectorTCopy = vectorT;                 // create a copy of it
    std::reverse(vectorTCopy.begin(), vectorTCopy.end()); // reverse copied vector

    if (vectorTCopy == vectorT) // compare
        std::cout << "[fn]This vector is a Palindrome."
                  << "\n";
    else
        std::cout << "[fn]This vector is not a Palindrome."
                  << "\n";

    return;
}

int main(void)
{
    std::random_device rd;
    std::mt19937       g(rd());

    std::vector<int> v1(2, 0);                                       // vector v1 of type int
    std::cout << "The first element of v1 is: " << v1.at(0) << "\n"; // print the first element 0

    v1.at(1) = 4;
    std::cout << "\nThe second element of v1 is: " << v1.at(1) << "\n"; // make sure the first element is set to 4

    v1.push_back(3); // adding elements sequentially
    v1.push_back(5);
    v1.push_back(16);
    v1.push_back(8);
    v1.push_back(2);
    v1.push_back(7);

    // print this integer vector
    printVector<int>(v1);
    std::cout << "\nThe size of vector v1 is: " << v1.size() << "\n";

    v1.resize(10, 0);
    printVector<int>(v1); // two zeros at the end as recently added element
    std::cout << "\nThe size of vector v1 is now: " << v1.size() << "\n";

    v1.pop_back(); // delete the last element
    printVector<int>(v1);
    std::cout << "\nThe size of vector v1 is now: " << v1.size() << "\n"; // should print 9

    v1.clear();
    std::cout << "\nClearing..."
              << "\n";
    printVector<int>(v1);                                               // empty vector -> nothing
    std::cout << "The size of vector v1 is now: " << v1.size() << "\n"; // should print 9

    /*
    std::cout << "Sorting..." << "\n";
    sort(v1.begin(), v1.end()); // sort function
    printVector<int>(v1); // print sorted ascending vector

    std::cout << "Reversing..." << "\n";
    reverse(v1.begin(), v1.end()); // reverse function
    printVector<int>(v1); // print reversed vector
    */

    std::vector<int> vA{1, 2, 3, 4, 5, 2, 7, 4, 1}; // creating int vector named 'vA'
    // vector<datatype> vectorName {num1, num2};
    std::cout << "\nA vector named \"vA\" has been created "
              << "with some random integers ranged from 1 to 10."
              << "\n"
              << "Sorting..."
              << "\n";
    std::sort(vA.begin(), vA.end());
    printVector<int>(vA); // print sorted

    std::cout << "\nReversing..."
              << "\n";
    std::reverse(vA.begin(), vA.end());
    printVector<int>(vA); // print reversed

    std::vector<char> vB{'B', 'S', 'T', 'W', 'S', 'K', 'A', 'W'}; // creating int vector named 'vB'
    std::cout << "\nA vector named \"vB\" with 8 characters has been created."
              << "\n"
              << "Sorting..."
              << "\n";
    std::sort(vB.begin(), vB.end());
    printVector<char>(vB); // print sorted

    std::cout << "\nReversing..."
              << "\n";
    std::reverse(vB.begin(), vB.end());
    printVector<char>(vB); // print reversed

    std::cout << "\nShuffling..."
              << "\n";
    std::shuffle(vB.begin(), vB.end(), g);
    printVector<char>(vB); // print shuffled

    // counting in vector A:
    std::cout << "\nIn vector A:"
              << "\n"
              << "The times element \"1\" is: " << count(vA.begin(), vA.end(), 1) << "\n"
              << "The times element \"2\" is: " << count(vA.begin(), vA.end(), 2) << "\n"
              << "The times element \"3\" is: " << count(vA.begin(), vA.end(), 3) << "\n"
              << "The times element \"4\" is: " << count(vA.begin(), vA.end(), 4) << "\n";

    // counting in vector B:
    std::cout << "\nIn vector B:"
              << "\n"
              << "The times element \"A\" is: " << count(vB.begin(), vB.end(), 'A') << "\n"
              << "The times element \"B\" is: " << count(vB.begin(), vB.end(), 'B') << "\n"
              << "The times element \"S\" is: " << count(vB.begin(), vB.end(), 'S') << "\n"
              << "The times element \"W\" is: " << count(vB.begin(), vB.end(), 'W') << "\n";

    // max_element in both vectors:
    // function "max_element()" returns an address
    std::cout << "\nConsulting the biggest element in both vectors..."
              << "\n"
              << "The max element is vector A is: " << *max_element(vA.begin(), vA.end()) << "\n"  // print 7
              << "The max element is vector B is: " << *max_element(vB.begin(), vB.end()) << "\n"; // print 'W'

    // min_element in both vectors:
    // function "min_element()" returns an address
    std::cout << "\nConsulting the smallest element in both vectors..."
              << "\n"
              << "The min element is vector A is: " << *min_element(vA.begin(), vA.end()) << "\n"  // print 1
              << "The min element is vector B is: " << *min_element(vB.begin(), vB.end()) << "\n"; // print 'A'

    // replace elements in both vectors:
    std::cout << "\nReplacing all \"1\"s in vector A..."
              << "\n";
    std::replace(vA.begin(), vA.end(), 1, 8); // replace all 1s with 8s
    sort(vA.begin(), vA.end());               // sort before printing
    printVector<int>(vA);                     // no 1s.

    std::cout << "\nReplacing all \"S\"s in vector B..."
              << "\n";
    replace(vB.begin(), vB.end(), 'S', 'C'); // replace all 'S' with 'C'
    sort(vB.begin(), vB.end());
    printVector<char>(vB);

    // squareAndPrint(9); // testing function
    //  for_each function
    std::cout << "\nSquaring vector A..."
              << "\n";
    std::for_each(vA.begin(), vA.end(), squareAndPrint); // only the function name

    // checking if it's palindrome int vectors:
    std::vector<int> testint{1, 2, 3, 2, 1};
    palindrome<int>(testint);

    std::vector<int> testint2{1, 2, 3, 4, 5};
    palindrome<int>(testint2);

    // checking if it's palindrome character vectors:
    std::vector<char> chartest1{'H', 'E', 'L', 'L', 'O'};
    palindrome<char>(chartest1); // not a palindrome

    std::vector<char> chartest2{'A', 'N', 'N', 'A'};
    palindrome<char>(chartest2); // a palindrome

    return 0;
}
