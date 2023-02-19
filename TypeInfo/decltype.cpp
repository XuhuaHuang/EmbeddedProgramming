/**
 * @file decltype.cpp
 * @author Xuhua Huang
 * @brief 
 * @version 0.9
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// g++ -o decltype.exe .\decltype.cpp -std=c++17
// ./decltype
// highlight: std::is_same<decltype(w), decltype(wht)>::value in <type_traits>
// and customized type-determining function is_same_type() 
// using typeid().name() and typeid().hash_code()
#if __has_include(<typeinfo>)
#include <typeinfo>
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <type_traits>

class White {};
class Black {};

// Un-comment the following line and comment out the line above
// to see difference after running is_same_type().
// using Black = White;

template<typename T, typename U>
bool is_same_type(const T& t, const U& u) {
    /**
     * @brief The following macro is required if this is defined in a stand-alone .h lib file.
     * To verify the depandency is present and included.
     */
#if __has_include(<typeinfo>)
#include <typeinfo>
#else
#error "Library <typeinfo> is missing."
#endif

    return typeid(t).hash_code() == typeid(u).hash_code();
}

template<typename T, typename U>
bool is_same_type() {
    bool _same_type = false;
    // std::cout << "Overload " << __func__ << "\n";
    if (typeid(T).hash_code() == typeid(U).hash_code()) {
        _same_type = true;
    }
    return _same_type;
}

int main(void) {

    White w;
    Black b;

    /**
     * @brief Explore the typeid().name() function.
     * Returns the length of the class name followed by the full class name.
     * Returned value can be assigned to an object of std::string.
     * operator[] and std::string::at() methods still apply.
     */
    std::cout << "White type: " << typeid(w).name() << "\n"; // 5White
    std::cout << "Black type: " << typeid(b).name() << "\n"; // 5Black

    /* Operation with the returned type. */
    const std::string class_name = typeid(w).name();
    std::cout << "Class name of object " << std::quoted("w") << ": " << class_name << "\n"
        << "Length: " << class_name[0] << "\n"; /* class_name.at(0) */

    /* Explicitly parse the name of the classes and objects. */
    std::cout << std::quoted("is_same_type<White, Black>(w, b)") << ": "
        << is_same_type<White, Black>(w, b) << "\n";

    /* Using decltype() to let the compiler dynamically derive the type. */
    std::cout << std::quoted("is_same_type<decltype(w), decltype(b)>(w, b)") << ": " 
        << is_same_type<decltype(w), decltype(b)>(w, b) << "\n";
    
    /* With overload function. */
    std::cout << std::quoted("is_same_type<decltype(w), decltype(b)>()") << ": "
        << is_same_type<decltype(w), decltype(b)>() << "\n";

    /* With std::is_same<T, U> from <type_traits>. */
    White wht; // create another instance of class White
    std::cout << std::quoted("std::is_same<decltype(w), decltype(wht)>::value") << ": "
        << std::is_same<decltype(w), decltype(wht)>::value << "\n";

    system("pause");
    return 0;
}
