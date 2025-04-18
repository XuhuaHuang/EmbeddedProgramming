// clang-format off
/*****************************************************************//**
 * \file   timer.cpp
 * \brief  Boost V1 timer, the new cpu_timer is added in V2.
 * 
 * To compile this file with g++ in PowerShell or bash:
 * $ g++ -o timer.exe -c .\timer.cpp -I C:\\boost\\boost_1_82_0 -std=c++2a
 * $ .\timer.exe
 * 
 * This is an old/depercated version of timer in boost; a compiler
 * warning is expected; however, it is still worthy to look at the API.
 * 
 * \author Xuhua Huang
 * \date   September 19, 2022
 *********************************************************************/
// clang-format on

#ifndef BOOST_TIMER_ENABLE_DEPRECATED
#define BOOST_TIMER_ENABLE_DEPRECATED
#include <boost/timer.hpp>
#endif

#include <iostream>

int main(void) {
    /* boost::timer */
    boost::timer t;

    std::cout << "Max timespan: " << t.elapsed_max() / 3600 << "h" << "\n"
              << "Min timespan: " << t.elapsed_min() << "s" << "\n"
              << "Time elapsed: " << t.elapsed() << "s" << "\n";

    return 0;
}
