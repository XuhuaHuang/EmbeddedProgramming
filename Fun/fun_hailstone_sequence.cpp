/*****************************************************************//**
 * \file   fun_hailstone_sequence.cpp
 * \brief  Generate a Hailstone sequence with C++
 *		     print vector with template function
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>
#include <vector>

#ifndef SIZE
#define SIZE 2000
#endif

using namespace std;

// funtion used to print vector with template
template<typename T>
void printVector(vector<T> vector)
{
	cout << "\n[fn][printVector]The content of received vector is listed: " << endl;

	typename std::vector<T>::iterator iter;
	for (iter = vector.begin(); iter < vector.end(); iter++)
		cout << *iter << endl;

	cout << "[fn][printVector]This is the end of the vector." << endl;

	return;
}

int main(void)
{
	int element;
	int count = 1;
	vector<int> sequence = {};

	cout << "Reminder: the first element of the sequence should be greater than 1." << endl
		   << "Please enter the first element of the Hailstone sequence: ";
	cin >> element;

	if (element > 1)
	{
		cout << "\nGenerating Hailstone sequence...\n\n";
		
		do
		{
			(element % 2) ? element = 3 * element + 1 : element /= 2;
			// output current count and value
			cout << "Current count: " << count << ", Element: " << element << endl;
			// increment count
			count++;
			// add new elemnt to vector<int> sequence
			sequence.push_back(element);
		} while (element > 1 && count <= SIZE);

		cout << "\nFinished generating sequence." << endl
		     << "Steps used to generate sequence: " << count - 1 << endl;
	}
	else if (element == 1)
	{
		cout << "Error! { 1 } is already a Hailstone sequence!" << endl
			   << "Please try again!" << endl;
	}
	else
	{
		cout << "Unable to recognize input. Fatal error." << endl
			   << "Aborting..." << endl;
	}

	cout << "\nCalling funtion \"printVector(vector T)\"" << endl;
	printVector(sequence);

	return 0;
}
