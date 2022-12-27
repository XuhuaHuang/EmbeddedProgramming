/*****************************************************************//**
 * \file   __func__.cpp
 * \brief  Demonstration of __cplusplus macro and __func__ signature
 * __func__ attribute of each function defaults to the name of such fn
 * __FUNCSIG__ equivalent with MSVC compiler
 * 
 * To compile on Windows:
 * $ g++ -o func.exe .\__func__.cpp -std=c++11
 * $ .\func.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#if __cplusplus < 201103L
#error "Should use C++ 11 implementation!"
#endif

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "../Util/log.h"

#ifndef __USR_NO_EXCEPT__
#define __USR_NO_EXCEPT__ true
#endif

/* Function set to not throwing any exceptions
 * as per requested by the user using a macro.
 * std::terminate will handle all the panicking.
 */
const char* hello() noexcept(__USR_NO_EXCEPT__) {
    // Equivalence of defining the following manually:
    // static const char* __func__ = "hello";
    std::cout << "\033[32m" << __PRETTY_FUNCTION__  << "\033[m" << "\n";
    return __func__;
}

const char* world() noexcept(__USR_NO_EXCEPT__) {
    // Equivalence of defining the following manually:
    // static const char* __func__ = "world";
    std::cout << "\033[32m" << __PRETTY_FUNCTION__ << "\033[m" << "\n";
    return __func__;
}

/* __func__ in struct */
typedef struct TestStruct {
public:
    TestStruct() : name(__func__) {}

    const char* getName(void) {
        std::cout << "\033[32m" << __PRETTY_FUNCTION__ << "\033[m" << "\n";
        return this->name;
    }

private:
    const char* name;
} TestStruct;

int main(void)
{
    /* Test __func__ predefined macro */
    std::cout << hello() << "\n" 
        << world() << "\n";
    LOG("Function call hello() returns: %s", hello());
    LOG("Function call world() returns: %s", world());

    /* Testing the LOG(...) macro */
    int x = 5;
    LOG("x = %d", x);
    
    /* Testing TestStruct constructor with __func__ */
    TestStruct* ts = new TestStruct();
    LOG("__func__ in TestStruct constructor has the value of: %s", ts->getName());
    delete ts;

    system("pause");
    return 0;
}
