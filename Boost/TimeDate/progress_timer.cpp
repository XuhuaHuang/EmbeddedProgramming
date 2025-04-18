// clang-format off
/*****************************************************************//**
 * \file   progress_timer.cpp
 * \brief  boost_progress inherits from boost::timer
 * The usage of the class is simple,
 * just need to declare it via `boost::progress_timer t`.
 * 
 * When it goes out of the scope, the destructor of the class is called
 * and the time elapsed since the object is created will be printed out.
 * 
 * To compile this file with g++ in PowerShell or bash:
 * $ g++ -o progress_timer.exe -c .\progress_timer.cpp -I C:\\boost\\boost_1_82_0 -std=c++2a
 * $ .\progress_timer.exe
 * 
 * \author Xuhua Huang
 * \date   September 19, 2022
 *********************************************************************/
// clang-format on

#include <boost/timer/progress_display.hpp>
#include <iostream>
#include <sstream>

int main(void) {
    boost::timer::progress_display prog{100};
    std::cout << prog.count() << "\n";

    return 0;
}
