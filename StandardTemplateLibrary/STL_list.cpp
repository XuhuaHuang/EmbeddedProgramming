/*****************************************************************//**
 * \file   STL_list.cpp
 * \brief  basic implementation of list
 * 
 * \ to be cobtinue: forward_list (C++11)
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream> 
#include <list> 
#include <iterator> 

using namespace std;

//function for printing the elements in a list
void showlist(list <int> listToPrint)
{
    list <int> ::iterator iterInt; // declare an iterInterator
    
    cout << "\n[fn]Printint list..." << endl; 
    for (iterInt = listToPrint.begin(); iterInt != listToPrint.end(); iterInt++) 
    {
        cout << *iterInt << "\t"; // iterator is a pointer-like object
    }
    cout << "\n[fn]Finished printing the list." << endl;
}

int main(void)
{
    list <int> list1, list2;
    // list <type> variable_name;

    for (int i = 0; i < 10; ++i)
    {
        list1.push_back(i * 2);
        list2.push_front(i * 3); // list filled with for loop
    }

    cout << "\nList 1 (list1) is : ";
    showlist(list1);

    cout << "\nList 2 (list2) is : ";
    showlist(list2);

    cout << "\nPrinting with \"list_name.front()\" and "
         << "\"list_name.back()\" function: " << endl
         << "Print first and last element of the list correspondingly" << endl
         << "\nlist1.front(): " << list1.front() << endl
         << "\nlist1.back(): " << list1.back() << endl;

    cout << "\nlist1.pop_front(): " << endl
         << "first element in the list removed" << endl;;
    list1.pop_front(); // first element removed
    showlist(list1);

    cout << "\nlist2.pop_back(): " << endl
         << "last element in the list removed" << endl;
    list2.pop_back(); // last element in the list removed
    showlist(list2); 

    cout << "\nlist1.reverse(): " << endl
         << "the order of contents in the list is reversed";
    list1.reverse(); // list 1 contents reversed
    showlist(list1); 

    cout << "\nlist2.sort(): " << endl
         << "contents in the list are sorted in ascending order";
    list2.sort(); // list 2 contents sorted
    showlist(list2); 

    return 0;
}
