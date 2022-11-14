/*****************************************************************//**
 * \file   hex_octal_string_brief.cpp
 * \brief  g++ -c .\hex_octal_string_brief.cpp -o hex_octal_string_brief.exe
 * ./hex_octal_string_brief.exe
 * 
 * \author Xuhua Huang
 * \date   November 14, 2020
 *********************************************************************/

#include <iostream>
#include <float.h>
#include <string>
#include <cmath>

//using std::cout;
//using std::cin;

int main(void)
{
    // boolean value
    bool life_is_good = true;
    std::cout << std::boolalpha << life_is_good << "\n";
    if (life_is_good) // brackets evaluate the condition and feedback either true or false
        std::cout << "This is True." << "\n";

    //float and double
    float a = 0;
    double b;
    long double c;

    std::cout << std::fixed << a << "\n";
    // std::fixed gets rid of scientific notation

    std::cout << LDBL_DIG << "\n";
    // this line is evaluating up to how many digits we can trust on these variables
    // 6 for float, 15 for double, 18 for long double

    // string
    std::string greeting = "What's up?";
    std::cout << greeting.find_first_of("aeiou") << "\n"; // string member modifier or methods
    /*	if not found, npos == -1
        however, it's an unsigned integer
        negative value makes it go 1 lower to a tremendously big
    */
    if (greeting.find_first_of("!") == -1)
        std::cout << "NOT FOUND!" << "\n";

    if (greeting.compare("What's up?") == 0)
        std::cout << "EQUALS!" << "\n";
    // compare function returns a bool 0 to indicate found

    // hex and octal int
    int x = 0x30; // 0x indicates this is a hex int
    // second digit is 16^1 = 16, 16 * 3 = 48

    int y = 030; // 0 indicates an octal int
    // second digit is 8^1 = 8, 8 * 3 = 24

    return 0;
}
