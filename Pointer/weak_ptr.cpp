/**
 * @file weak_ptr.cpp
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Demonstration of weak_ptr feature in C++11.
 * @version 0.1
 * @date 2021-11-26
 * 
 * To compile on Windows:
 * $ g++ -o weak_ptr.exe .\weak_ptr.cpp -std=c++11
 * $ .\weak_ptr.exe
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <memory>
#include <stdlib.h>

#if __cplusplus < 201103L
    #error "Should use C++ 11 implementation!"
#endif

void check_weak_ptr(std::weak_ptr<int>& wp) {
    /* std::weak_ptr::lock() returns a rvalue of std::shared_ptr object. */
    std::shared_ptr<int> sp = wp.lock();
    // if the memory wp points to is no longer valid, it returns nullptr.
    
    /* Check the content of sp. */
    if (sp != nullptr) {
        std::cout << "Pointer is valid: " << *sp << "\n";
    } 
    else {
        std::cout << "Pointer is invalid." << "\n";
    }
    
    /* Empty return statement for consistency of the control flow. */
    return;
}

int main(void) {
    std::shared_ptr<int> sp1(new int(22));
    std::shared_ptr<int> sp2 = sp1; // this operation will increase the reference counter by 1
    // sp2 and sp1 points to the same block of memory
    std::weak_ptr<int> wp = sp1;
    // wp does NOT own the memory

    std::cout << "std::shared_ptr<int> sp1 value: " << *sp1 << "\n";
    std::cout << "std::shared_ptr<int> sp2 value: " << *sp2 << "\n";

    check_weak_ptr(wp);
    sp1.reset();
    std::cout << "sp1 has been reseted. std::shared_ptr<int> sp2 value: " << *sp2 << "\n";

    check_weak_ptr(wp);
    sp2.reset();
    /**
     * @brief both sp1 and sp2 are reseted. reference count is now 0.
     * since weak_ptr does not own the block, it's no longer valid.
     * use the following line to verify
     */
    check_weak_ptr(wp);

    system("pause");
    return 0;
}