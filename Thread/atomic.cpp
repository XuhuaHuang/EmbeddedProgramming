/**
 * @file atomic.cpp
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Spawning multiple threads with standardized vector (std::vector<typename>)
 * to work with an atomic variable.
 * @version 0.1
 * @date 2022-01-27
 * 
 * g++ atomic.cpp -o atomic -lpthread -std=c++17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

/* Define some shared resource
 * with std::atomic<typename>
 */
static std::atomic<int> shared_value = 0; // applying RAII principle

void increment_shared_value(void) {
    shared_value++;
}


int main(void)
{
    /* Create a lot of (1000) threads */
    std::vector<std::thread> threads;

    for(int i = 0; i < threads.size(); ++i) {
        threads.push_back(std::thread(increment_shared_value));
    }
    
    /* Join created threads with range-based for loops */
    // auto decays to std::thread
    for(auto& thread : threads) {
        thread.join();
    }

    /* Retreive the result */
    std::cout << "Result of shared_value = " << shared_value << "\n";

    return 0;
}