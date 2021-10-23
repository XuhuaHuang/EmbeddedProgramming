/*****************************************************************//**
 * \file   learn_maps.cpp
 * \brief  The order of the elements in the map does NOT matter
 * Constant time complexity when accessing value
 * Map is a collection data structure of key-value pairs (JSON)
 * TODO: std::unordered_map
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> employees = {
	{"John", 3},
	{"Jill", 4},
	{"Rick", 5},
	{"Elaine", 6}
};

map<string, char> template_demo = {
	{"Apple", 'A'},
	{"Beta", 'B'},
	{"Cat", 'C'},
	{"Dog", 'D'}
};

void print(const pair<string, int>& employee)
{
	if (employee.second < 5)
		cout << employee.first << endl;
}

/* Provide template function to print any map. */
namespace Util {
	template<typename T, typename U>
	void printMap(map<T, U>& const mp)
	{
		// `typename` is essential in the following for loop
		for (typename std::map<T, U>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
			std::cout << "Key: " << itr->first << ", value: " << itr->second << std::endl;
	}
}

int main(void)
{
	/* Create a map to map ASCII character and decimal. */
	map<char, int> mpASCII = {
		{'C', 67}, // each element is a pair
		{'F', 70}, // access through pair.first and
		{'I', 73}  // pair.second method
	};

	cout << mpASCII['C'] << endl
		 << mpASCII['F'] << endl;

	/* Insert a key and corresponding value. */
	// Informal way of inserting: mpASCII['U'] = 85;
	mpASCII.insert(pair<char, int>('U', 85));

	cout << mpASCII['U'] << endl;

	/* Access element in a pair using first/second index. */
	cout << pair<char, int>('U', 85).first << endl
		 << pair<char, int>('U', 85).second << endl;

	/* Erase an element in the map. */
	// Emptying a map: map.clear()
	// Identify an empty map: map.empty()
	// Identify the map Size; map.size()
	mpASCII.erase('C'); // the first element of the map is removed

	/* Iterate through a map. */
	for (map<char, int>::iterator itr = mpASCII.begin(); itr != mpASCII.end(); ++itr)
	{
		cout << "Key: " << itr->first << ", Value: " << itr->second << endl;
	}

	/* More map example. */
	/* Map the times a character shows up in a string. */
	string test = "Hello world my name is Xuhua Huang";
	map<char, int> charFreq = {};
	
	for (int i = 0; i < test.length(); ++i)
	{
		char elem = test[i];

		// map.find() returns an iterator
		// returns map.end() if not found
		if (charFreq.find(elem) == charFreq.end())
		{
			charFreq[elem] = 0;
		}
		charFreq[elem]++;
	}

	for (map<char, int>::iterator itr = charFreq.begin(); itr != charFreq.end(); ++itr)
	{
		cout << "Character: \"" << itr->first << "\", Occupancy: " << itr->second << endl;
	}

	/* Testing external map and non-template print function. */
	for_each(employees.begin(), employees.end(), print);
	// print is passed a call-back function

	/* Test template function to print map. */
	Util::printMap(employees);
	Util::printMap(template_demo);

	system("pause");
	return 0;
}