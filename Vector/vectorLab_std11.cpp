/*****************************************************************//**
 * \file   vectorLab_std11.cpp
 * \brief  using template function for various vectors
 * 
 * \author Xuhua Huang
 * \date   November 2020
 * \last modified: March 2021
 *********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// function prototype:
void squareAndPrint(int x);

template<class T>
void printVector(vector<T> argVector)
{
	cout << "\n[fn]The content of this vector is listed: " << endl;

	typename vector<T>::iterator iter; // keyword 'typename' is required for iterator
	for (iter = argVector.begin(); iter < argVector.end(); iter++)
		cout << *iter << endl; // dereference the iterator to print content
	
	cout << "[fn]This is the end of the vector." << endl;
	return;
}

template<class T>
void palindrome(vector<T> vectorT)
{
	printVector<T>(vectorT); // print the original/received vector
	
	vector<T> vectorTCopy = vectorT; // create a copy of it
	reverse(vectorTCopy.begin(), vectorTCopy.end()); // reverse copied vector

	if (vectorTCopy == vectorT) // compare
		cout << "[fn]This vector is a Palindrone." << endl;
	else
		cout << "[fn]This vector is not a Palindrone." << endl;
	
	return;
}

int main(void)
{
	vector<int> v1(2, 0); // vector v1 of type int
	cout << "The first element of v1 is: " << v1.at(0) << endl; // print the first element 0

	v1.at(1) = 4;
	cout << "\nThe second element of v1 is: " << v1.at(1) << endl; // make sure the first element is set to 4

	v1.push_back(3); // adding elements sequentially
	v1.push_back(5);
	v1.push_back(16);
	v1.push_back(8);
	v1.push_back(2);
	v1.push_back(7);

	// print this integer vector
	printVector<int>(v1);
	cout << "\nThe size of vector v1 is: " << v1.size() << endl;

	v1.resize(10, 0);
	printVector<int>(v1); // two zeros at the end as recently added element
	cout << "\nThe size of vector v1 is now: " << v1.size() << endl;

	v1.pop_back(); // delete the last element
	printVector<int>(v1);
	cout << "\nThe size of vector v1 is now: " << v1.size() << endl; // should print 9

	v1.clear();
	cout << "\nClearing..." << endl;
	printVector<int>(v1); // empty vector -> nothing
	cout << "The size of vector v1 is now: " << v1.size() << endl; // should print 9

	/*
	cout << "Sorting..." << endl;
	sort(v1.begin(), v1.end()); // sort function
	printVector<int>(v1); // print sorted accedending vector

	cout << "Reversing..." << endl;
	reverse(v1.begin(), v1.end()); // reverse function
	printVector<int>(v1); // print reversed vector
	*/

	vector<int> vA{ 1,2,3,4,5,2,7,4,1 }; // creating int vector named 'vA'
	// vector<datatype> vectorName {num1, num2}; 
	cout << "\nA vector named \"vA\" has been created "
		 << "with some random integers ranged from 1 to 10." << endl
		 << "Sorting..." << endl;
	sort(vA.begin(), vA.end());
	printVector<int>(vA); // print sorted

	cout << "\nReversing..." << endl;
	reverse(vA.begin(), vA.end());
	printVector<int>(vA); // print reversed

	vector<char> vB{ 'B','S','T', 'W','S','K','A','W' }; // creating int vector named 'vB'
	cout << "\nA vector named \"vB\" with 8 characters has been created." << endl
		 << "Sorting..." << endl;
	sort(vB.begin(), vB.end());
	printVector<char>(vB); // print sorted

	cout << "\nReversing..." << endl;
	reverse(vB.begin(), vB.end());
	printVector<char>(vB); // print reversed

	cout << "\nShuffling..." << endl;
	random_shuffle(vB.begin(), vB.end());
	printVector<char>(vB); // print shuffled

	// counting in vector A:
	cout << "\nIn vector A:" << endl
		 << "The times element \"1\" is: " << count(vA.begin(), vA.end(), 1) << endl
		 << "The times element \"2\" is: " << count(vA.begin(), vA.end(), 2) << endl
		 << "The times element \"3\" is: " << count(vA.begin(), vA.end(), 3) << endl
		 << "The times element \"4\" is: " << count(vA.begin(), vA.end(), 4) << endl;

	// counting in vector B:
	cout << "\nIn vector B:" << endl
		 << "The times element \"A\" is: " << count(vB.begin(), vB.end(), 'A') << endl
		 << "The times element \"B\" is: " << count(vB.begin(), vB.end(), 'B') << endl
		 << "The times element \"S\" is: " << count(vB.begin(), vB.end(), 'S') << endl
		 << "The times element \"W\" is: " << count(vB.begin(), vB.end(), 'W') << endl;

	// max_elementin both vectors:
	// function "max_element()" returns an address
	cout << "\nConsulting the biggest element in both vectors..." << endl
		 << "The max element is vector A is: " << *max_element(vA.begin(), vA.end()) << endl // print 7
		 << "The max element is vector B is: " << *max_element(vB.begin(), vB.end()) << endl; // print 'W'

	// min_elementin both vectors:
	// function "min_element()" returns an address
	cout << "\nConsulting the smallest element in both vectors..." << endl
		 << "The min element is vector A is: " << *min_element(vA.begin(), vA.end()) << endl  // print 1
		 << "The min element is vector B is: " << *min_element(vB.begin(), vB.end()) << endl; // print 'A'

	// replace elements in both vectors:
	cout << "\nReplacing all \"1\"s in vector A..." << endl;
	replace(vA.begin(), vA.end(), 1, 8); // replace all 1s with 8s
	sort(vA.begin(), vA.end()); // sort before printing
	printVector<int>(vA); // no 1s.

	cout << "\nReplacing all \"S\"s in vector B..." << endl;
	replace(vB.begin(), vB.end(), 'S', 'C'); // replace all 'S' with 'C'
	sort(vB.begin(), vB.end());
	printVector<char>(vB);

	//squareAndPrint(9); // testing function
	// for_each function
	cout << "\nSquaring vector A..." << endl;
	for_each(vA.begin(), vA.end(), squareAndPrint); // only the function name

	// checking if it's palindrome int vectors:
	vector<int> testint{ 1,2,3,2,1 };
	palindrome<int>(testint);

	vector<int> testint2{ 1,2,3,4,5 };
	palindrome<int>(testint2);

	// checking if it's palindrome character vectors:
	vector<char> chartest1{ 'H','E','L','L','O' };
	palindrome<char>(chartest1); // not a palindrome

	vector<char> chartest2{ 'A','N','N','A' };
	palindrome<char>(chartest2); // a palindrome

	return 0;
}

void squareAndPrint(int x)
{
	cout << "Squared: " << (x * x) << endl; // x^2 did NOT work not sure why
	return;
}
