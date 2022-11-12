/*****************************************************************//**
 * \file   STL_array_2D.cpp
 * \brief  example on how to work with 2D array/vector
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <array>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
	cout << "\nCreating a multidimentional array" << endl
		 << "which groups 1-12 in groups of 3" << endl
		 << "printint the 2D array with nested for loops.\n" << endl;

	int data1[][4] = // [][4] is required to specify 4 grouped elements
	{ 
		{1, 2, 3}, 
		{4, 5, 6}, 
		{7, 8, 9}, 
		{10, 11, 12} 
	};
	
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << data1[row][col] << "\t";
		}
		cout << "\n";
	}

	cout << "\nCreating a multidimentional vector" << endl
		 << "it will also be printed wirh nested for loops." << endl;

	vector<vector<int>> data2 =
	{
		{13, 14, 15},
		{16, 17, 18},
		{19, 20, 21},
		{22, 23, 24}
	};
	
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << data2[row][col] << "\t";
		}
		cout << "\n";
	}

	return 0;
}
