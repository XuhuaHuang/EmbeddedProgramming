/*****************************************************************//**
 * \file   STL_deque.cpp
 * \brief  brief on Double Ended Queue (deque)
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream> 
#include <deque> 

using namespace std;

// creat a function to print double ended queue (deque)
void showdq(deque <int> queueToPrint)
{
    deque <int> ::iterator iterInt; // declare an iterator

    cout << "\n[fn]Printing double ended queue..." << endl;
    for (iterInt = queueToPrint.begin(); iterInt != queueToPrint.end(); iterInt++)
    {
        cout << *iterInt << "\t";
    }
    cout << "\n[fn]Finished printing double ended queue." << endl;
}

int main(void)
{
    // deque <type> variable_name;
    deque <int> dequeue1;
    dequeue1.push_back(10);
    dequeue1.push_front(20);
    dequeue1.push_back(30);
    dequeue1.push_front(15);
    cout << "The deque dequeue1 is : ";
    showdq(dequeue1);

    cout << "\ndequeue1.size(): " << dequeue1.size();
    cout << "\ndequeue1.max_size(): " << dequeue1.max_size() << endl;

    cout << "\nAccessing the third element indexed 2: " << endl
         << "dequeue1.at(2): " << dequeue1.at(2) << endl // print third element

         << "\nAccessing the first elemnent with front() member function" << endl
         << "dequeue1.front(): " << dequeue1.front() << endl // print first element
 
         << "\nAccessing the last element with back() member function" << endl
         << "dequeue1.back(): " << dequeue1.back() << endl; // print last element

    cout << "\npop_front() member function removes the first element" << endl
         << "dequeue1.pop_front(): ";
    dequeue1.pop_front();
    showdq(dequeue1); // 15 removed

    cout << "\npop_back() member function removes the last element" << endl
         << "dequeue1.pop_back(): ";
    dequeue1.pop_back();
    showdq(dequeue1); // 30 removed

    return 0;
}
