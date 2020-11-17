/*****************************************************************//**
 * \file   STL_array.cpp
 * \brief  templatized array in C++
 * 
 * Document highlight: range-based for-loop
 *					   std::array<type, size> = {}; // initialization
 *					   at(index) 
 *					   get<index> array/tuple_name
 *					   array/tuple_name[index]
 * 
 * \author 1879700
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <array>		// at(index)
#include <tuple>		// get<index> array/tuple_name

using namespace std;

// function prototype
void printArray(array<int, 20> data);

int main(void)
{
	// initializing the array elements
	std::array<int, 6> data = { 1, 2, 3, 4, 5, 6 };
	cout << "\nA 6-element array named \"data\" has been created with elements incrementing from 1 to 6" << endl;
	
	// printArray(data); // umcomment this line if you want to use the printArray function

	cout << "\nUsing different member function to print..." << endl;

	// printing array elements using at() 
	cout << "\nThe array elements are printed using \"at(index)\" member function: ";
	for (int i = 0; i < 6; i++)
		cout << data.at(i) << " ";
	cout << endl;

	// printing array elements using get() 
	cout << "\nThe array elements are printed using \"get<index> array/tuple_name\" member function: "
		 << get<0> (data) << " " << get<1> (data) << " "
		 << get<2> (data) << " " << get<3> (data) << " "
		 << get<4> (data) << " " << get<5> (data) << " "
		 << endl;

	// printing array elements using operator[] 
	cout << "\nThe array elements are printed using method \"array_name[index]\": ";
	for (int i = 0; i < 6; i++)
		cout << data[i] << " ";
	cout << endl;
	
	cout << "\nUsing range-based for loop to print the element of array \"data\": ";
	for (int elem : data)
		cout << elem << " ";
	cout << endl;

	return 0;
}

// function to print the array
void printArray(array<int, 6> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << "\t";
	}
	cout << "\n";

	return;
}
