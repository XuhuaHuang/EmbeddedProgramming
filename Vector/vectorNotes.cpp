#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<double> dv);
void func(double value);

int main(void)
{
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
	vector<double> dv; // a vector containning doub#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<double> dv);
void func(double value);

int main(void)
{
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
	vector<double> dv; // a vector containning double using default constructor
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
	int c = count(dv.begin(), dv.end(),9.9);
	cout << c << endl;
	
	return 0;
}


void printVector(vector<double> dv)
{
	vector<double>::iterator iterdouble;
	for(iterdouble = dv.begin();iterdouble < dv.end(); iterdouble++)
	{
		cout << *iterdouble << endl;
	}
}


void func(double value)
{
	cout << "Inside  function func(): ";
	cout << value << endl;	
}
le using default constructor
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
	int c = count(dv.begin(), dv.end(),9.9);
	cout << c << endl;
	
	return 0;
}


void printVector(vector<double> dv)
{
	vector<double>::iterator iterdouble;
	for(iterdouble = dv.begin();iterdouble < dv.end(); iterdouble++)
	{
		cout << *iterdouble << endl;
	}
}


void func(double value)
{
	cout << "Inside  function func(): ";
	cout << value << endl;	
}
