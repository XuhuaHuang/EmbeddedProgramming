/**
 * @file compile_time_vector_unittest.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright ueg (c) 2023
 *
 */

#include "compile_time_vector.hpp"
#include <iostream>
#include <string>
#include <vector>

#define log std::cout << __LINE__ << " " << std::boolalpha << std::fixed

int main(void)
{
    {
        // constexpr linear_container::compile_time_vector<int, 3U> v{10, 20, 30};
        // log << std::boolalpha << v.empty() << "\n";
        // log << v.size() << "\n";
        // log << linear_container::get<0>(v) << "\n";
        // log << boost::fusion::at<boost::mpl::int_<0>>(v) << "\n";
        /* constexpr */ // linear_container::compile_time_vector<1U, int> v{10};
    }

    {
        // create a fusion::vector of three integers
        auto my_vector = boost::fusion::vector<int, int, int>{1, 2, 3};
        log << typeid(my_vector).name() << "\n";

        using namespace linear_container;
        log << "get<0>(my_vector): " << get<0>(my_vector) << " of type " << get_type<0>(my_vector).pretty_name()
            << "\n";
        log << "get<1>(my_vector): " << get<1>(my_vector) << " of type " << get_type<1>(my_vector).pretty_name()
            << "\n";
        log << "get<2>(my_vector): " << get<2>(my_vector) << " of type " << get_type<2>(my_vector).pretty_name()
            << "\n";
    }

    {
        using vector_type = boost::fusion::vector<int, std::string, bool, double>;

        vector_type v{10, "Boost API", true, 3.14};
        // auto v = boost::fusion::make_vector(10, "Boost", true, 3.14);

        // log << typeid(v).name() << "\n";
        // log << boost::typeindex::type_id<decltype(v)>().pretty_name() << "\n";
        log << "first element of vector_type v: " << boost::fusion::at<boost::mpl::int_<0>>(v) << "\n";

        using namespace linear_container;

        log << "get<0>(v): " << get<0>(v) << "\n";
        log << "get<1>(v): " << get<1>(v) << "\n";
        log << "get<2>(v): " << get<2>(v) << "\n";
        log << "get<3>(v): " << get<3>(v) << "\n";

        auto v2            = push_back(v, 'X');
        // log << typeid(v2).name() << "\n";
        // log << boost::typeindex::type_id<decltype(v2)>().pretty_name() << "\n";

        using vector2_type = boost::fusion::vector<int, std::string, bool, double, char>;
        vector2_type v2_   = push_back(v, 'X');
        log << typeid(v2_).name() << "\n";
        log << boost::fusion::at<boost::mpl::int_<4>>(v2_) << "\n";          // 'X'
        log << get_type<4>(v2_) << "\n";                                     // char

        log << "boost::fusion::size(v): " << boost::fusion::size(v) << "\n"; // 4
        log << "linear_container::size_of(v): " << linear_container::size_of(v) << "\n";

        log << "boost::fusion::size(v2): " << boost::fusion::size(v2) << "\n"; // 5
        log << "linear_container::size_of(v2): " << size_of(v2) << "\n";

        // log << "linear_container::get_type<4>(v2): " << linear_container::get_type<4>(v2).pretty_name() << "\n";

        log << "boost::fusion::back(v2): " << boost::fusion::back(v2) << "\n"; // 'X' of type char

        log << "invoking boost::fusion::for_each() with v2: "
            << "\n";
        boost::fusion::for_each(v2, [&](const auto elem) -> void { std::cout << elem << ", "; });
        log << "\n";

        // boost::typeindex::type_id<element_type>().pretty_name()
        //                                        ^^ calling the constructor
        //                                          ^^ calling the member function
        constexpr int index = 3;
        using element_type  = decltype(get<index>(v));
        log << "element at index " << index << " has type " << boost::typeindex::type_id<element_type>().pretty_name()
            << "\n";

        log << "element at index " << index << " has type " << get_type<index>(v).pretty_name() << "\n";
    }

    {
        constexpr linear_container::compile_time_vector<1U, int> v{};
        log << std::boolalpha << v.empty() << "\n";
        log << v.size() << "\n";
        log << linear_container::get<0>(v) << "\n";
    }

    return EXIT_SUCCESS;
}
