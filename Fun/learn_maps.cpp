/*****************************************************************//**
 * \file   learn_maps.cpp
 * \brief  The order of the elements in the map does NOT matter
 * Constant time complexity when accessing value
 * Map is a collection data structure of key-value pairs (JSON)
 * 
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

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

		// map.find(0 returns an iterator
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

	system("pause");
	return 0;
}