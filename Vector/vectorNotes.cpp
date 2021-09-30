/*****************************************************************//**
 * \file   vectorNotes.cpp
 * \brief  When the vector is full, it creates a new one with 50% more
 * space and move(or copy) the original data.
 * Note that the memory is allocated in a contiguous manner.
 * 
 * Despite the fact objects copy mechanism when stored in vector,
 * remember to provide a sanitized copy constructor.
 * 
 * Less commonly-seen member function of <vector>:
 * 1) .reserve(capacity)
 * 2) .emplace_back(elem) is a better approach to avoid copying
 * 
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace Util {
	namespace vector {

		/* Template to print a std::vector with O(n). */
		template<typename T>
		static void print_vec(const std::vector<T>& Vec) {
			/* Loop through the vector with range-based for loop. */
			for (const T& t : Vec)
				std::cout << t << std::endl;

			return; // add empty return statement for consistency.
		}
	}
}

void printVector(vector<double> dv);
void func(double value);

int main(void)
{
	/* Using template constructor */
	vector<int> v1(6,0); // create an array of 6 elements and initialize them to zero
	cout << v1.at(0) << endl; // display zero from position indexed 0
	
	v1.push_back(9); // adds one element and sets it to 9
	cout << v1.size() << endl;
	
	v1.resize(10,0); // add three more zeros to the vector
	
	v1.at(8) = 7;
	cout << v1.at(8) << endl;
	
	
	// int vector iterator
	vector<int>::iterator iterint;
	for(iterint = v1.begin();iterint < v1.end();iterint++)
	{
		cout << *iterint << endl;
	}
	
	
	// double vector
	vector<double> dv; // a vector containing double using default constructor
	dv.push_back(1.2);
	dv.push_back(3.4);
	dv.push_back(5.6);
	dv.push_back(7.8);
	dv.push_back(9.9);
	
	vector<double>::iterator iterdouble;
	for(iterdouble = dv.begin();iterdouble < dv.end(); iterdouble++)
	{
		cout << *iterdouble << endl;
	}
	
	/*
	dv.clear(); // wipes the entire array
	vector<double>::iterator iterdouble2;
	for(iterdouble2 = dv.begin();iterdouble2 < dv.end(); iterdouble2++)
	{
		cout << *iterdouble << endl;
	}
	*/
	
	
	// ALGORITHMS
	sort(dv.begin(), dv.end()); // sort function
	printVector(dv);
	
	reverse(dv.begin(), dv.end()); // reverse function
	printVector(dv);
	
	// "for_each" - calls function func and pass each element in vector
	for_each(dv.begin(),dv.end(),func);
	
	// counts the number of times the element shows up
	int c = count(dv.begin(), dv.end(), 9.9);
	cout << c << endl;
	
	system("pause");
	return 0;
}


void printVector(vector<double> dv)
{
	/* Constant references could not be used here
	 * due the nature of an iterator.
	 */
	vector<double>::iterator iterdouble;
	for(iterdouble = dv.begin();iterdouble < dv.end(); iterdouble++)
	{
		cout << *iterdouble << endl;
	}

	return;
}


void func(double value)
{
	cout << "Inside  function func(): ";
	cout << value << endl;

	return;
}
