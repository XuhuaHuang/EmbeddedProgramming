/*****************************************************************//**
 * \file   vectorLab.cpp
 * \brief  Lab on std::vector<typename T> use cases and
 * std::vector<typename T>::iterator use cases
 *
 * \author Xuhua Huang
 * \date   October 13, 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

// function prototype:
void printIntVector(std::vector<int>);
void printCharVector(std::vector<char>);
void squareAndPrint(int);
void palindrome(std::vector<int>);
void palindrome(std::vector<std::string>);
void palindrome(std::vector<char>);

int main(void)
{
    std::random_device rd;
    std::mt19937       g(rd());

    std::vector<int> v1(2, 0); // std::vector v1 of type int
    std::cout << "The first element of v1 is: " << v1.at(0) << "\n"; // print the first element 0

    v1.at(1) = 4;
    std::cout << "The second element of v1 is: " << v1.at(1) << "\n"; // make sure the first element is set to 4

    v1.push_back(3); // adding elements sequentially
    v1.push_back(5);
    v1.push_back(16);
    v1.push_back(8);
    v1.push_back(2);
    v1.push_back(7);

    // std::string iterator std::string::iterator iter;
    // std::vector<int>::iterator iterv1; // std::vector<datatype>::iterator iterName;
    printIntVector(v1);
    std::cout << "The size of std::vector v1 is: " << v1.size() << "\n" << "\n";

    v1.resize(10, 0);
    printIntVector(v1);							// two zeros at the end as recently added element
    std::cout << "The size of std::vector v1 is now: " << v1.size() << "\n" << "\n";

    v1.pop_back(); // delete the last element
    printIntVector(v1);
    std::cout << "The size of std::vector v1 is now: " << v1.size() << "\n"; // should print 9

    v1.clear();
    std::cout << "\nClearing..." << "\n";
    printIntVector(v1); // empty std::vector -> nothing
    std::cout << "The size of std::vector v1 is now: " << v1.size() << "\n"; // should print 9

    /*
    std::cout << "Sorting..." << "\n";
    sort(v1.begin(), v1.end()); // sort function
    printIntVector(v1); // print sorted acceding std::vector

    std::cout << "Reversing..." << "\n";
    reverse(v1.begin(), v1.end()); // reverse function
    printIntVector(v1); // print reversed std::vector
    */

    std::vector<int> vA{ 1,2,3,4,5,2,7,4,1 }; // creating int std::vector named 'vA'
    // std::vector<datatype> std::vectorName {num1, num2}; 
    /*
    vA.push_back(1);
    vA.push_back(2);
    vA.push_back(3);
    vA.push_back(4);
    vA.push_back(5);
    vA.push_back(2);
    vA.push_back(7);
    vA.push_back(4);
    vA.push_back(1); // writing all elements into the std::vector
    */
    std::cout << "\nSorting..." << "\n";
    std::sort(vA.begin(), vA.end());
    printIntVector(vA); // print sorted

    std::cout << "\nReversing..." << "\n";
    std::reverse(vA.begin(), vA.end());
    printIntVector(vA); // print reversed

    std::vector<char> vB{ 'B','S','T', 'W','S','K','A','W' }; // creating int std::vector named 'vB'
    /*
    vB.push_back('B');
    vB.push_back('S');
    vB.push_back('T');
    vB.push_back('W');
    vB.push_back('S');
    vB.push_back('K');
    vB.push_back('A');
    vB.push_back('W'); // writing all characters to the char std::vector
    */

    std::cout << "\nSorting..." << "\n";
    std::sort(vB.begin(), vB.end());
    printCharVector(vB); // print sorted

    std::cout << "\nReversing..." << "\n";
    std::reverse(vB.begin(), vB.end());
    printCharVector(vB); // print reversed

    std::cout << "\nShuffling..." << "\n";
    std::shuffle(vB.begin(), vB.end(), g);
    printCharVector(vB); // print shuffled

    // counting in std::vector A:
    std::cout << "\nIn std::vector A:" << "\n";
    std::cout << "The times element \"1\" is: " << count(vA.begin(), vA.end(), 1) << "\n";
    std::cout << "The times element \"2\" is: " << count(vA.begin(), vA.end(), 2) << "\n";
    std::cout << "The times element \"3\" is: " << count(vA.begin(), vA.end(), 3) << "\n";
    std::cout << "The times element \"4\" is: " << count(vA.begin(), vA.end(), 4) << "\n";

    // counting in std::vector B:
    std::cout << "\nIn std::vector B:" << "\n";
    std::cout << "The times element \"A\" is: " << count(vB.begin(), vB.end(), 'A') << "\n";
    std::cout << "The times element \"B\" is: " << count(vB.begin(), vB.end(), 'B') << "\n";
    std::cout << "The times element \"S\" is: " << count(vB.begin(), vB.end(), 'S') << "\n";
    std::cout << "The times element \"W\" is: " << count(vB.begin(), vB.end(), 'W') << "\n";

    // max_element in both std::vectors:
    std::cout << "\nConsulting the biggest element in both std::vectors..." << "\n";
    std::cout << "The max element is std::vector A is: " << *max_element(vA.begin(), vA.end()) << "\n"; // print 7
    std::cout << "The max element is std::vector B is: " << *max_element(vB.begin(), vB.end()) << "\n"; // print 'W'

    // min_element in both std::vectors:
    std::cout << "\nConsulting the smallest element in both std::vectors..." << "\n";
    std::cout << "The min element is std::vector A is: " << *min_element(vA.begin(), vA.end()) << "\n"; // print 1
    std::cout << "The min element is std::vector B is: " << *min_element(vB.begin(), vB.end()) << "\n"; // print 'A'

    // replace elements in both std::vectors:
    std::cout << "\nReplacing all \"1\"s in std::vector A..." << "\n";
    std::replace(vA.begin(), vA.end(), 1, 8); // replace all 1s with 8s
    std::sort(vA.begin(), vA.end()); // sort before printing
    printIntVector(vA); // no 1s.

    std::cout << "\nReplacing all \"S\"s in std::vector B..." << "\n";
    std::replace(vB.begin(), vB.end(), 'S', 'C'); // replace all 'S' with 'C'
    std::sort(vB.begin(), vB.end());
    printCharVector(vB);

    //squareAndPrint(9); // testing function
    // for_each function
    std::cout << "\nSquaring std::vector A..." << "\n";
    std::for_each(vA.begin(), vA.end(), squareAndPrint); // only the function name

    // checking if it's palindrome int std::vectors:
    std::vector<int> testint{ 1,2,3,2,1 };
    palindrome(testint);

    std::vector<int> testint2{ 1,2,3,4,5 };
    palindrome(testint2);

    // checking if it's palindrome std::string std::vectors: 
    std::string testword = "HELLO"; // not a palindrome
    std::vector<std::string> testString{ testword };
    palindrome(testString); // should print not a palindrome

    // for std::vector<std::string>, I think the reason why it does NOT work is I had to go into the first element and reverse the element.
    // instead of reversing the std::string std::vector

    std::string testword2 = "ANNAA";
    std::vector<std::string> testString2{ testword2 };
    palindrome(testString2); // should print is a palindrome

    std::vector<char> chartest1{ 'H','E','L','L','O' };
    std::cout << "\nThe word HELLO" << "\n";
    palindrome(chartest1); // not a palindrome

    std::vector<char> chartest2{ 'A','N','N','A' };
    std::cout << "The word ANNA" << "\n";
    palindrome(chartest2); // a palindrome

    return 0;
}


void printIntVector(std::vector<int> intv)
{
    std::vector<int>::const_iterator iterint;
    std::cout << "The content of this integer std::vector is listed: " << "\n";

    for (iterint = intv.begin(); iterint < intv.end(); iterint++)
    {
        std::cout << *iterint << "\n";
    } // end for

    std::cout << "This is the end of the integer std::vector." << "\n";
}

void printCharVector(std::vector<char> charv)
{
    std::vector<char>::const_iterator iterchar;
    std::cout << "The content of this character std::vector is listed: " << "\n";

    for (iterchar = charv.begin(); iterchar < charv.end(); iterchar++)
    {
        std::cout << *iterchar << "\n"; // print v3 using std::vectors
    } // end for

    std::cout << "This is the end of the integer std::vector." << "\n";
}

void squareAndPrint(int x)
{
    std::cout << "Squared: " << (x * x) << "\n"; // x^2 did NOT work not sure why
    return;
}

void palindrome(std::vector<int> vint)
{
    std::vector<int> vintCopy = vint; // copy to a new std::vector for comparison
    reverse(vintCopy.begin(), vintCopy.end());

    if (vintCopy == vint)
        std::cout << "\nThis integer std::vector is a Palindrome." << "\n";
    else
        std::cout << "\nThis integer std::vector is not a Palindrome." << "\n";
    return;
}

void palindrome(std::vector<std::string> vString)
{
    std::vector<std::string> vStringCopy = vString; // copy to a new std::vector for comparison
    // std::cout << vstd::stringCopy.at(0) << "\n"; // test
    std::reverse(vStringCopy.begin(), vStringCopy.end());
    // std::cout << vstd::stringCopy.at(0) << "\n"; // test

    if (vStringCopy == vStringCopy)
        std::cout << "\nThis std::string std::vector is a Palindrome." << "\n";
    else
        std::cout << "\nThis std::string std::vector is not a Palindrome." << "\n";
    return;
}

void palindrome(std::vector<char> vchar)
{
    std::vector<char> vcharCopy = vchar;
    reverse(vcharCopy.begin(), vcharCopy.end());

    if (vcharCopy == vchar)
        std::cout << "\nThis std::string std::vector is a Palindrome." << "\n";
    else
        std::cout << "\nThis std::string std::vector is not a Palindrome." << "\n";

    return;
}
