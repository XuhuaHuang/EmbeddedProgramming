/*****************************************************************//**
 * \file   thread_sleep.cpp
 * \brief  basic thread member function
 * Keep the program doing something until the user presses Enter key
 * 
 * 1) std::this_thread::get_id()
 * 2) std::this_thread::sleep_for()
 * 3) join()
 *
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>

static bool s_finished = false;

void doWork()
{
    using namespace std::literals::chrono_literals;

    std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";

    while (!s_finished)
    {
        std::cout << "Working on something..." << "\n";
        std::this_thread::sleep_for(1s);
        // std::this_thread refers to the current running thread
    }
    std::cout << "Done working" << "\n";
}

int main(void)
{
    std::thread worker(doWork); // immediately start the thread

    std::cin.get(); // wait for the user to press Enter
    s_finished = true;

    worker.join(); // wait for the thread to finish executing
    // continue on main thread
    std::cout << "finished" << "\n";

    std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";

    system("pause");
    return 0;
}
