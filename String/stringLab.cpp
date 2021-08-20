/*****************************************************************//**
 * \file   stringNotes.cpp
 * \brief  lab on strings in C++
 *
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	// requirement 1
	string userInput1;
	cout << "Please enter your favourite idiom:" << endl;
	getline(cin, userInput1);
	cout << "The sentence you just entered is: " + userInput1 << endl;  // for testing purpose only
	
	string dogName;
	cout << "Please enter your dog's name. We promise we won't do any harm to your loved ones." << endl;
	cin.ignore() >> dogName;
	
	string dogBreed;
	cout << "Do you mind telling us its breed?" << endl;
	cin.ignore() >> dogBreed;
	
	cout << "Great! " + dogName + " is of breed " + dogBreed << endl;
	cout << "This is the end of requirement 1." << endl;
	
	// requirement 2 find and erase
	string fixedStr = "she sells seashells from the sea shore.";
	
	size_t search = fixedStr.find('s',0);
	
	while(search!= string::npos)
	{
		fixedStr.erase(search,1);
		search = fixedStr.find('s',0);
		cout << "It is now: " + fixedStr << endl; // printing the lines  to see one "s" less each line
	} // end while
	
	
	// requirement 3: insert letter "q" to the center of any word
	cout << "\nWarning! I am going to insert letter \"q\" to the center of your string." << endl;
	string userInput2;
	cin >> userInput2;
	int strlength =  userInput2.length();
	cout << "\nThe size of the word you just entered is: " << strlength << endl; // for testing purpose
	
	int halflength = strlength/2;	
	if(halflength%2 == 1)
		userInput2.insert(halflength+1, 1, 'q');
	else if(halflength%2 == 0)
		userInput2.insert(halflength, 1, 'q');
	
	cout << "New \"word\" is: " << userInput2 << endl;
	
	cout << "\nHow many \"q\"s do you want to insert to the center of the word?" << endl;
	int numq = 0;
	cin >> numq;
	userInput2.insert(halflength, numq-1, 'q'); // there was already one q existed
	cout << "Now the new \"word\" is: " << userInput2 << endl;
	
	// requirement 5 using iterators
	cout << "Using iterators..." << endl;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	cout << "The original alphabetical string is: " << alpha << endl;
	
	string::iterator iteralpha; // define an iterator object
	
	for(int x = 0; x <= (int)alpha.length(); x++) // forcing it to of type int
	{
		for(iteralpha = alpha.begin(); iteralpha < alpha.begin() + x; iteralpha++)
		{
			cout << *iteralpha;
		}
		cout << endl;
	}
	
	
	// requirement 6 comparing strings
	cout << "Comparing string..." << endl;
	string fruit1, fruit2, fruit3;
	
	cout << "Please enter three different fruits: " << endl;
	cout << "\nThe first one:\n";
	cin >> fruit1;
	cout << "The second one:\n";
	cin >> fruit2;
	cout << "The second one:\n";
	cin >> fruit3;
	
	if( (fruit1 < fruit2) && (fruit1 < fruit3) ) // fruit1 comes first
	{
		cout << endl << fruit1 << " comes first alphabetically." << endl;
		
		if(fruit2 < fruit3)
			cout << fruit3 << " comes least alphabetically." << endl;
		else // fruit3 < fruit2
			cout << fruit2 << " comes least alphabetically." << endl;
	}
	else if( (fruit2 < fruit1) && (fruit2 < fruit3) ) // fruit2 comes first
	{
		cout << endl << fruit2 << " comes first alphabetically." << endl;
		
		if(fruit1 < fruit3)
			cout << fruit3 << " comes least alphabetically." << endl;
		else // fruit3 < fruit1
			cout << fruit1 << " comes least alphabetically." << endl;
	}
	else // fruit3 comes first
	{
		cout << endl << fruit3 << " comes first alphabetically." << endl;
		
		if(fruit1 < fruit2)
			cout << fruit2 << " comes least alphabetically." << endl;
		else // fruit2 < fruit1
			cout << fruit1 << " comes least alphabetically." << endl;
	}
	
	return 0;
}
