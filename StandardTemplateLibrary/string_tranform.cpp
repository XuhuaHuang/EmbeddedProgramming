// C++ program to convert whole string to 
// uppercase or lowercase using STL.

#include <iostream>
#include <algorithm>
#include <string>

int main(void)
{
    std::string first_name = "Xuhua";
    // using transform() function and ::toupper in STL
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::toupper);
    std::cout << first_name << "\n"; // XUHUA

    std::string last_name = "Huang";
    // using transform() function and ::tolower in STL
    std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);
    std::cout << last_name << "\n";  // "huang"

    return 0;
}
