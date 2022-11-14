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
 * $ g++ -o progress_timer.exe -c .\progress_timer.cpp -I C:\\boost\\boost_1_80_0 -std=c++2a
 * $ .\progress_timer.exe
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 19, 2022
 *********************************************************************/

#include <iostream>
#include <sstream>
#include <boost/progress.hpp>

auto main(void) -> int {
    /* boost::progress_timer */
    boost::progress_timer t;
    std::cout << t.elapsed() << "\n";

    /**
     * The destructor of the class boost:progress_timer also allows
     * outputting to other output stream than std::cout (default option).
     * For example, std::ofstream, std::ostringstream.
     * Or we can use cout.rdbuf() to redirect the buffer output.
     */
    std::stringstream ss;
    {
        boost::progress_timer t(ss);
    }
    std::cout << ss.str() << "\n";

    system("pause");
    return EXIT_SUCCESS;
}

