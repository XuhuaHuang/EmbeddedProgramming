#include <iostream>
#include <string>
using namespace std;
// Xuhua Huang 1879700

int main(void)
{
	
	string theBird; // declare a variable of data type string
	theBird = "Bluejay"; // initialize the string variable theBird
	cout << theBird << endl;
	string action = "fly";
	string sentence = theBird + " can " + action; // concatenate in string
	cout << sentence << endl;
	
	
	string str;	
	cout << "Enter a  sentence: ";
	getline(cin, str); // use the function cin and store it in the object str
	//cin.ignore(); // ignore the \n characters;
	cout << str << endl;
	
	
	string name1 = "Bob"; 
	string name2 = "Alex";
	
	if (name1 < name2) // check alphabectical order
		cout << "Bob is before Alex." << endl;
	else
		cout << "Alex is before Bob." << endl;
	
	
	string glue = "sticky";
	cout << glue << endl;
	glue.erase(4,2); // erase function in the string class
	// start erasing at the index 4 and erase 2 characters
	cout << "The string after erasing is: " << glue << endl;
	
	
	size_t x = glue.find('i',0); // return the index of the character i, starting at position  k0
	// find function only looks for one character and finds the first character encountered
	// size_t is the string class equvalent of int
	cout << "The charater \"i\" is found akt positon: " << x << endl;
	
	
	string hello = "hello";
	size_t y = hello.find('l',3); // trying to find the letter l starting at position 3
	if(y == string::npos) // string no position
		cout << "The letter \"l\" is not found in string hello." << endl;
	else
		cout << "The letter \"l\" is found at position " << y << endl;
	
	
	// iterator
	string tree = "deciduous";
	string::iterator iterstr; // pointer
	
	for (iterstr = tree.begin(); iterstr < tree.end(); iterstr++)
	{
		cout << *iterstr;
	}
	
	
	return 0;
}
