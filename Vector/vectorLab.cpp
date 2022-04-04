#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

// 1879700 Xuhua Huang

using namespace std;

// function prototype:
void printIntVector(vector<int> intv);
void printCharVector(vector<char> charv);
void squareAndPrint(int x);
void palindrome(vector<int> vint);
void palindrome(vector<string> vstring);
void palindrome(vector<char> vchar);

int main (void)
{
	
	vector<int> v1(2,0); // vector v1 of type int
	cout << "The first element of v1 is: " << v1.at(0) << endl; // print the first element 0
	
	v1.at(1) = 4;
	cout << "The second element of v1 is: " << v1.at(1) << endl; // make sure the first element is set to 4
	
	v1.push_back(3); // adding elements sequentially
	v1.push_back(5);
	v1.push_back(16);
	v1.push_back(8);
	v1.push_back(2);
	v1.push_back(7);
	
	// string iterator string::iterator iter;
	// vector<int>::iterator iterv1; // vector<datatype>::iterator iterName;
	printIntVector(v1);	
	cout << "The size of vector v1 is: " << v1.size() << endl << endl;
	
	v1.resize(10,0);
	printIntVector(v1);							// two zeros at the end as recently added element
	cout << "The size of vector v1 is now: " << v1.size() << endl << endl;
	
	v1.pop_back(); // delete the last element
	printIntVector(v1);
	cout << "The size of vector v1 is now: " << v1.size() << endl; // should print 9
	
	v1.clear();
	cout << "\nClearing..." << endl;
	printIntVector(v1); // empty vector -> nothing
	cout << "The size of vector v1 is now: " << v1.size() << endl; // should print 9
	
	/*
	cout << "Sorting..." << endl;
	sort(v1.begin(), v1.end()); // sort function
	printIntVector(v1); // print sorted acceding vector
	
	cout << "Reversing..." << endl;
	reverse(v1.begin(), v1.end()); // reverse function
	printIntVector(v1); // print reversed vector
	*/
	
	vector<int> vA {1,2,3,4,5,2,7,4,1}; // creating int vector named 'vA'
	// vector<datatype> vectorName {num1, num2}; 
	/*
	vA.push_back(1);
	vA.push_back(2);
	vA.push_back(3);
	vA.push_back(4);
	vA.push_back(5);
	vA.push_back(2);
	vA.push_back(7);
	vA.push_back(4);
	vA.push_back(1); // writing all elements into the vector
	*/
	cout << "\nSorting..." << endl;
	sort(vA.begin(), vA.end());
	printIntVector(vA); // print sorted
	
	cout << "\nReversing..." << endl;
	reverse(vA.begin(), vA.end());
	printIntVector(vA); // print reversed
	
	vector<char> vB {'B','S','T', 'W','S','K','A','W'}; // creating int vector named 'vB'
	/*
	vB.push_back('B');
	vB.push_back('S');
	vB.push_back('T');
	vB.push_back('W');
	vB.push_back('S');
	vB.push_back('K');
	vB.push_back('A');
	vB.push_back('W'); // writing all characters to the char vector
	*/
	
	cout << "\nSorting..." << endl;
	sort(vB.begin(), vB.end());
	printCharVector(vB); // print sorted
	
	cout << "\nReversing..." << endl;
	reverse(vB.begin(), vB.end());
	printCharVector(vB); // print reversed
	
	cout << "\nShuffling..." << endl;
	random_shuffle(vB.begin(), vB.end());
	printCharVector(vB); // print shuffled
	
	// counting in vector A:
	cout << "\nIn vector A:" << endl;
	cout << "The times element \"1\" is: " << count(vA.begin(), vA.end(), 1) << endl;
	cout << "The times element \"2\" is: " << count(vA.begin(), vA.end(), 2) << endl;
	cout << "The times element \"3\" is: " << count(vA.begin(), vA.end(), 3) << endl;
	cout << "The times element \"4\" is: " << count(vA.begin(), vA.end(), 4) << endl;
	
	// counting in vector B:
	cout << "\nIn vector B:" << endl;
	cout << "The times element \"A\" is: " << count(vB.begin(), vB.end(), 'A') << endl;
	cout << "The times element \"B\" is: " << count(vB.begin(), vB.end(), 'B') << endl;
	cout << "The times element \"S\" is: " << count(vB.begin(), vB.end(), 'S') << endl;
	cout << "The times element \"W\" is: " << count(vB.begin(), vB.end(), 'W') << endl;
	
	// max_elementin both vectors:
	cout << "\nConsulting the biggest element in both vectors..." << endl;
	cout << "The max element is vector A is: " << *max_element(vA.begin(), vA.end()) << endl; // print 7
	cout << "The max element is vector B is: " << *max_element(vB.begin(), vB.end()) << endl; // print 'W'
	
	// min_elementin both vectors:
	cout << "\nConsulting the smallest element in both vectors..." << endl;
	cout << "The min element is vector A is: " << *min_element(vA.begin(), vA.end()) << endl; // print 1
	cout << "The min element is vector B is: " << *min_element(vB.begin(), vB.end()) << endl; // print 'A'
	
	// replace elements in both vectors:
	cout << "\nReplacing all \"1\"s in vector A..." << endl;
	replace(vA.begin(), vA.end(), 1, 8); // replace all 1s with 8s
	sort(vA.begin(), vA.end()); // sort before printing
	printIntVector(vA); // no 1s.
	
	cout << "\nReplacing all \"S\"s in vector B..." << endl;
	replace(vB.begin(), vB.end(), 'S', 'C'); // replace all 'S' with 'C'
	sort(vB.begin(), vB.end());
	printCharVector(vB);
	
	//squareAndPrint(9); // testing function
	// for_each function
	cout << "\nSquaring vector A..." << endl;
	for_each(vA.begin(), vA.end(), squareAndPrint); // only the function name
	
	// checking if it's palindrome int vectors:
	vector<int> testint {1,2,3,2,1};
	palindrome(testint);
	
	vector<int> testint2 {1,2,3,4,5};
	palindrome(testint2);
	
	// checking if it's palindrome string vectors: 
	string testword = "HELLO"; // not a palindrome
	vector<string> teststring { testword };
	palindrome(teststring); // should print not a palindrome
	
	// for vector<string>, I think the reason why it does NOT work is I had to go into the first element and reverse the element.
	// instead of reversing the string vector
	
	string testword2 = "ANNAA";
	vector<string> teststring2 { testword2 };
	palindrome(teststring2); // should print is a palindrome
	
	vector<char> chartest1 {'H','E','L','L','O' };
	cout << "\nThe word HELLO" << endl;
	palindrome(chartest1); // not a palindrome
	
	vector<char> chartest2 { 'A','N','N','A' };
	cout << "The word ANNA" << endl;
	palindrome(chartest2); // a palindrome
	
	return 0;
}


void printIntVector(vector<int> intv)
{
	vector<int>::const_iterator iterint;
	cout << "The content of this integer vector is listed: " << endl;
	
	for(iterint = intv.begin(); iterint < intv.end(); iterint++)
	{
		cout << *iterint << endl;
	} // end for
	
	cout << "This is the end of the integer vector." << endl;
}

void printCharVector(vector<char> charv)
{
	vector<char>::const_iterator iterchar;
	cout << "The content of this character vector is listed: " << endl;
	
	for(iterchar = charv.begin(); iterchar < charv.end(); iterchar++)
	{
		cout << *iterchar << endl; // print v3 using vectors
	} // end for
	
	cout << "This is the end of the integer vector." << endl;	
}

void squareAndPrint(int x)
{
	cout << "Squared: " << (x*x) << endl; // x^2 did NOT work not sure why
	return;
}

void palindrome(vector<int> vint)
{
	vector<int> vintCopy = vint; // copy to a new vector for comparison
	reverse( vintCopy.begin(), vintCopy.end() );
	
	if(vintCopy == vint)
		cout << "\nThis integer vector is a Palindrome." << endl;
	else
		cout << "\nThis integer vector is not a Palindrome." << endl;
	return;
}

void palindrome(vector<string> vstring)
{
	vector<string> vstringCopy = vstring; // copy to a new vector for comparison
	// cout << vstringCopy.at(0) << endl; // test
	reverse( vstringCopy.begin(), vstringCopy.end() );
	// cout << vstringCopy.at(0) << endl; // test
	
	if(vstringCopy == vstring)
		cout << "\nThis string vector is a Palindrome." << endl;
	else
		cout << "\nThis string vector is not a Palindrome." << endl;
	return;
}

void palindrome(vector<char> vchar)
{
	vector<char> vcharCopy = vchar;
	reverse( vcharCopy.begin(), vcharCopy.end() );
	
	if(vcharCopy == vchar)
		cout << "\nThis string vector is a Palindrome." << endl;
	else
		cout << "\nThis string vector is not a Palindrome." << endl;
	
	return;
}
