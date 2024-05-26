/*****************************************************************//**
 * \file   use_string_ref.cpp
 * \brief  Usage demonstration of boost version of std::string_view.
 * Read-only view/reference of std::string objects to prevent copying.
 * 
 * \author Xuhua Huang
 * \date   December 07, 2022
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <boost/utility/string_ref.hpp>

auto main(void) -> int {

    const char* c_str = { "Days of Future Past" };
    std::string cpp_str(c_str);

    boost::string_ref c_str_ref(c_str);
    boost::string_ref cpp_str_ref(cpp_str);
    assert(!c_str_ref.empty() && !cpp_str.empty());
    assert(cpp_str_ref.to_string() == cpp_str);

    assert(c_str == cpp_str && c_str_ref == c_str && cpp_str_ref == cpp_str);

    boost::string_ref first_4_chars(c_str, 4); // "Days"
    // note: boost::string_ref also supports substr()
    assert(cpp_str_ref.front()  == 'D');
    assert(first_4_chars == cpp_str.substr(0, 4));

    auto first_five_chars = [](boost::string_ref str_ref) -> boost::string_ref {
        std::cout << __FUNCSIG__ << "\n";
        return str_ref.substr(0, 5);
    };
    assert(cpp_str_ref.substr(0, 5) == first_five_chars(cpp_str_ref));

    std::cout << "\033[32mAll assertions are successful! The boost::string_ref is doing its magic!\033[m" << "\n";

    system("pause");
    return EXIT_SUCCESS;
}
