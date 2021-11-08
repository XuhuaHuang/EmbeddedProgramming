// g++ -o decltype.exe .\decltype.cpp -std=c++17
// ./decltype

#if __has_include(<typeinfo>)
#include <typeinfo>
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>


class White {};
class Black {};

// Un-comment the following line and comment out the line above
// to see difference after running is_same_type().
// using Black = White;

template<typename T, typename U>
bool is_same_type(const T& t, const U& u) {
    // bool same_type = false;
#if __has_include(<typeinfo>)
#include <typeinfo>
#else
#error "Library <typeinfo> is missing."
#endif

    return typeid(t).hash_code() == typeid(u).hash_code();
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
    std::cout << "White type: " << typeid(w).name() << std::endl; // 5White
    std::cout << "Black type: " << typeid(b).name() << std::endl; // 5Black

    /* Operation with the returned type. */
    const std::string class_name = typeid(w).name();
    std::cout << "Class name of object " << std::quoted("w") << ": " << class_name << std::endl
        << "Length: " << class_name[0] << std::endl; /* class_name.at(0) */

    std::cout << "\n\n" << is_same_type<White, Black>(w, b) << "\n";

    system("pause");
    return 0;
}