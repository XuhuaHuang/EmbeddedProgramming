/*****************************************************************//**
 * \file   Numbers.hpp
 * \brief  Pointer Lab Header File - class Numbers
 *
 * Notice: all "cout" statements inside a function are appened
 * after signature "[fn]" which stands for printing from function
 *
 * [DECONST] printed from default constructor
 * [OLCONST] printed from overloaded constructor
 * [DEST] printed from destructor
 *
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/

#ifndef NUMBERS_HPP
#define NUMBERS_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

class Numbers
{
public:
    // set and get functions:
    void setSize(int newSize) { size = newSize; }
    int getSize() { return size; }

    void setPtrNum(double* newPtrNum) { ptrNumber = newPtrNum; }
    double* getPtrNum() { return ptrNumber; }

    // overloaded constructor and destructor:
    Numbers(int sizeOfArray); // overloaded constructor
    ~Numbers();

    void store(int arrayIndex, double numToAdd);
    double retrieve(int arrayIndex);
    double average();

private:
    int size;
    double* ptrNumber;
};

Numbers::Numbers(int sizeofArray) // overloaded constructor with signed std::cout statements
{
    setSize(sizeofArray);
    ptrNumber = new double[getSize()];

    std::cout << "\n[OLCONST]\"Numbers::Numbers(int) is called by compiller." << "\n"
        << "[OLCONST]Size of array noe set to: " << getSize() << "\n"
        << "[OLCONST]Pointer to array initialized." << "\n";
}

Numbers::~Numbers()
{
    std::cout << "\n[DEST]Destructing...Deleting array pointer..." << "\n";

    delete ptrNumber;

    std::cout << "[DEST]Done. Array pointer erased." << "\n";
}

void Numbers::store(int arrayIndex, double numToAdd)
{
    *(ptrNumber + arrayIndex) = numToAdd;

    std::cout << "\n[fn]New element added to index: " << arrayIndex << "\n"
        << "[fn]Content of added element: " << numToAdd << "\n";

    return;
}

double Numbers::retrieve(int arrayIndex)
{
    double value = *(ptrNumber + arrayIndex);

    std::cout << "\n[fn]Retreiving element at index: " << arrayIndex << "\n"
        << "[fn]Content of retreived element: " << value << "\n";

    return value;
}

double Numbers::average()
{
    double sum = 0;
    for (int i = 0; i < getSize(); i++)
    {
        std::cout << "\n[fn]Retrieving element indexed: " << i << " from the average() function";
        sum += retrieve(i);
    }
    double result = sum / getSize();

    return result;
}

#endif

