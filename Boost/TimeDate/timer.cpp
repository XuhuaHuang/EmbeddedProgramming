/*****************************************************************//**
 * \file   timer.cpp
 * \brief  Boost V1 timer, the new cpu_timer is added in V2.
 * 
 * To compile this file with g++ in PowerShell or bash:
 * $ g++ -o timer.exe -c .\timer.cpp -I C:\\boost\\boost_1_80_0 -std=c++2a
 * $ .\timer.exe
 * 
 * This is an old/depercated version of timer in boost; a compiler
 * warning is expected; however, it is still worthy to look at the API.
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 19, 2022
 *********************************************************************/

#include <iostream>
#include <boost/timer.hpp>

auto main(void) -> int {

    /* boost::timer */
    boost::timer t;

    std::cout << "Max timespan: " << t.elapsed_max() / 3600 << "h" << "\n"
        << "Min timespan: " << t.elapsed_min() << "s" << "\n"
        << "Time elapsed: " << t.elapsed() << "s" << "\n";

    system("pause");
    return EXIT_SUCCESS;
}
