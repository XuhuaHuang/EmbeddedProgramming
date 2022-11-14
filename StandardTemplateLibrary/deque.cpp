/*****************************************************************//**
 * \file   deque.cpp
 * \brief  brief on Double Ended Queue (deque)
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream> 
#include <deque> 

// create a function to print double ended queue (deque)
void showdq(std::deque<int>& queueToPrint)
{
    std::deque<int>::iterator iterInt; // declare an iterator

    std::cout << "\n[fn]Printing double ended queue..." << "\n";
    for (iterInt = queueToPrint.begin(); iterInt != queueToPrint.end(); iterInt++)
    {
        std::cout << *iterInt << "\t";
    }
    std::cout << "\n[fn]Finished printing double ended queue." << "\n";
}

int main(void)
{
    // std::deque<type> variable_name;
    std::deque <int> dequeue1;
    dequeue1.push_back(10);
    dequeue1.push_front(20);
    dequeue1.push_back(30);
    dequeue1.push_front(15);
    std::cout << "The deque dequeue1 is : ";
    showdq(dequeue1);

    std::cout << "\ndequeue1.size(): " << dequeue1.size();
    std::cout << "\ndequeue1.max_size(): " << dequeue1.max_size() << "\n";

    std::cout << "\nAccessing the third element indexed 2: " << "\n"
         << "dequeue1.at(2): " << dequeue1.at(2) << "\n" // print third element

         << "\nAccessing the first element with front() member function" << "\n"
         << "dequeue1.front(): " << dequeue1.front() << "\n" // print first element
 
         << "\nAccessing the last element with back() member function" << "\n"
         << "dequeue1.back(): " << dequeue1.back() << "\n"; // print last element

    std::cout << "\npop_front() member function removes the first element" << "\n"
         << "dequeue1.pop_front(): ";
    dequeue1.pop_front();
    showdq(dequeue1); // 15 removed

    std::cout << "\npop_back() member function removes the last element" << "\n"
         << "dequeue1.pop_back(): ";
    dequeue1.pop_back();
    showdq(dequeue1); // 30 removed

    return 0;
}
