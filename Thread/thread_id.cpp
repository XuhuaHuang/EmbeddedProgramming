/*****************************************************************//**
 * \file   thread_id.cpp
 * \brief  contains usage for std::thread constructor w/ overloading
 *		   thread id and some other public member function
 *
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include<iostream>
#include<thread>
#include<chrono>

// function prototype
void pause_thread(int);
void is_main_thread();

// global id contains id for main()
std::thread::id main_thread_id = std::this_thread::get_id();

int main(void)
{
    std::thread threads[5]; // array of 5 default constructed threads 

    std::cout << "Spawning 5 threads..." << "\n";
    for (int i = 0; i < 5; i++)
        threads[i] = std::thread(pause_thread, i + 1); // call function pauseThread with for loop

    std::cout << "Done spawning threads. Now waiting for them to join:" << "\n";

    for (int i = 0; i < 5; i++)
    {
        if (threads[i].joinable())
            threads[i].join();
    }

    std::cout << "All threads joined!" << "\n";

    // swap thread
    // thread_name.swap(std::thread & Other);
    threads[0].swap(threads[1]);

    // determine thread id
    is_main_thread(); // determined / scoped as main thread
    std::thread th(is_main_thread); // custom thread "th" overloaded constructed
                                    // explicit thread (Fn&& fn, Args&&... args);
    th.join(); // join custom thread

    return 0;
}

void pause_thread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "Pause of " << n << " seconds ended" << "\n";
    return;
}

void is_main_thread()
{
    if (main_thread_id == std::this_thread::get_id())
        std::cout << "This is the main thread." << "\n"; // invoked when main() gets called
    else
        std::cout << "This is not the main thread." << "\n";
}
