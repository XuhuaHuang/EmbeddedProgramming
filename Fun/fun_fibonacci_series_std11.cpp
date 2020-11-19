/*****************************************************************//**
 * \file   fun_fibonacci_series_std11.cpp
 * \brief  work with C++11 to generate a Fibonacii series
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include<vector>
#include <string>

using namespace std;

#ifndef _fibo_h_
#define _fibo_h_
#include <vector>
class Fibonacci
{
private:
    int size;
    vector<long> data;

public:
    // constructor that inherits the item constructor
    Fibonacci(int size) : size(size) {}
    
    // other member functions
    void create_series(void);
    void get_data(void);
};
#endif // _fibo_h_ 

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        int value = stoul(argv[1], nullptr, 10);
        static Fibonacci Fibo(value);
        Fibo.create_series();
        Fibo.get_data();
    }

	return 0;
}

// creates a Fibonacci series
void Fibonacci::create_series(void)
{
    data.push_back(0);
    data.push_back(1);
    for (int i = 2; i < size; ++i)
    {
        data.push_back(data[i - 2] + data[i - 1]);
    }
}

// method is used to print the series
void Fibonacci::get_data(void)
{
    for (long i : data) // range based for loops
    {
        cout << i << endl;
    }
}
