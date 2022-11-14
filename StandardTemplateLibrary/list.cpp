/*****************************************************************//**
 * \file   list.cpp
 * \brief  basic implementation of list
 * 
 * \ to be continue: forward_list (C++11)
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include<iostream> 
#include<list>
#include<string>
#include<iterator>

extern std::list<std::string> knownLangsList { "C++", "Python", "Cython", "Rust", "Java" };
extern std::list<std::string> mainLangsList { "C++", "Python" };

// function for printing an integer list
void showlist(std::list<int> listToPrint)
{
    std::cout << "\n[fn]Printing list..." << "\n";

    std::list<int>::iterator iterInt; // declare an iterator named "iterInt"
    for (iterInt = listToPrint.begin(); iterInt != listToPrint.end(); iterInt++) 
        std::cout << *iterInt <<  " "; // iterator is a pointer-like object

    std::cout << "\n[fn]Finished printing the list." << "\n";
    return;
}

/**
 * Updated August 21, 2021.
 * Added generic function to print list with C++ template
 */
namespace util 
{
    template<class T>
    void printList(std::list<T> argList)
    {
        std::cout << "\n[fn]Printing list..." << "\n";

        typename std::list<T>::iterator iter; // keyword "typename" is required for iterator
        for (iter = argList.begin(); iter != argList.end(); ++iter)
            std::cout << *iter << " "; // dereference the iterator to print content

        std::cout << "\n[fn]Finished printing the list." << "\n";
        return;
    }
}

int main(int argc, char** argv)
{
    std::list<int> list1, list2;
    // list <type> variable_name;

    for (int i = 0; i < 10; ++i)
    {
        list1.push_back(i * 2);
        list2.push_front(i * 3); // list filled with for loop
    }

    std::cout << "\nList 1 (list1) is: ";
    showlist(list1);

    std::cout << "\nList 2 (list2) is: ";
    showlist(list2);

    std::cout << "\nPrinting with \"list_name.front()\" and "
         << "\"list_name.back()\" function: " << "\n"
         << "Print first and last element of the list correspondingly" << "\n"
         << "\nlist1.front(): " << list1.front() << "\n"
         << "\nlist1.back(): " << list1.back() << "\n";

    std::cout << "\nlist1.pop_front(): " << "\n"
         << "first element in the list removed" << "\n";;
    list1.pop_front(); // first element removed
    showlist(list1);

    std::cout << "\nlist2.pop_back(): " << "\n"
         << "last element in the list removed" << "\n";
    list2.pop_back(); // last element in the list removed
    showlist(list2); 

    std::cout << "\nlist1.reverse(): " << "\n"
         << "the order of contents in the list is reversed";
    list1.reverse(); // list 1 contents reversed
    showlist(list1); 

    std::cout << "\nlist2.sort(): " << "\n"
         << "contents in the list are sorted in ascending order";
    list2.sort(); // list 2 contents sorted
    showlist(list2);

    /* Test template function util::printList(std::list<T>) */
    util::printList(knownLangsList);
    util::printList(mainLangsList);

    return 0;
}
