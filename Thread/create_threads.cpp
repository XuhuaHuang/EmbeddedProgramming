/*****************************************************************//**
 * \file   create_threads.cpp
 * \brief  contains notes on 3 different ways to create threads with
 *	<threads> library introduced in C++11
 *
 * \author Xuhua Huang
 * \date   June 2021
 *********************************************************************/

#include <iostream>
#include <thread>

/**
* std::thread threadObj(<CALLBACK>);
*
* std::thread accepts the following:
* 1) function pointer
* 2) function objects
* 3) lambda functions
*/

void threadFn()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "\nFunction named \"threadFn\" executing..." << std::endl;
    }
}

/* Class definition used to create objects used to create thread */
class DisplayThread
{
public:
    void operator()()
    {
        for (int i = 0; i < 10; ++i)
        {
            std::cout << "\nOverloaded operator \"DisplayThread::operator()()\" executing..." << std::endl;
        }
    }
};

void printFromMainThread()
{
    for (int i = 0; i < 10; ++i)
        std::cout << "\nPrinting from main thread..." << std::endl;
}

int main(void)
{
    /* Create a thread with function pointer */
    std::thread threadFnPtr(threadFn); // threadFn is parsed as a function pointer

    printFromMainThread();
    threadFnPtr.join(); // cleans up memory and and force main to wait until threadObj finishes up

    /* Create a thread with function objects */
    std::thread threadFnObj((DisplayThread()));

    printFromMainThread();
    threadFnObj.join();

    /* Create a thread with lambda */
    std::thread threadLambda(
        []() {
            for (int i = 0; i < 10; ++i)
                std::cout << "\nLambda executing..." << std::endl;
        }
    );

    printFromMainThread();
    threadLambda.join();

    std::cout << "\nExit of main function" << std::endl;
    return 0;
}