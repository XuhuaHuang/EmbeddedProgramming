// clang-format off
/*****************************************************************//**
 * \file   std_printf.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   December 20, 2022
 *********************************************************************/
// clang-format on

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>

int main()
{
    const char* s = "Hello";

    std::printf("Strings:\n");     // same as std::puts("Strings:");
    std::printf("\t[%10s]\n", s);  // 10 characters, allign right
    std::printf("\t[%-10s]\n", s); // - sign, allign left
    std::printf("\t[%*s]\n", 10, s);
    std::printf("\t[%-10.*s]\n", 4, s); // 10 chars, - sign allign left, prints 4 chars
    std::printf("\t[%-*.*s]\n", 10, 4, s);

    std::printf("Characters:\t%c %%\n", 'A');

    std::printf("Integers:\n");
    std::printf("\tDecimal:    \t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4, -4);
    std::printf("\tHexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
    std::printf("\tOctal:      \t%o %#o %#o\n", 10, 10, 4);

    std::printf("Floating point:\n");
    std::printf("\tRounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
    std::printf("\tPadding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
    std::printf("\tScientific:\t%E %e\n", 1.5, 1.5);
    std::printf("\tHexadecimal:\t%a %A\n", 1.5, 1.5);
    std::printf("\tSpecial values:\t0/0=%g 1/0=%g\n", 0.0 / 0.0, 1.0 / 0.0);

    std::printf("Variable width control:\n");
    std::printf("\tright-justified variable width: '%*c'\n", 5, 'x');
    int r = std::printf("\tleft-justified variable width : '%*c'\n", -5, 'x');
    std::printf("(the last printf printed %d characters)\n", r);

    std::printf("Fixed-width types:\n");
    std::uint32_t val = std::numeric_limits<std::uint32_t>::max();
    std::printf("\tLargest 32-bit value is %" PRIu32 " or %#" PRIx32 "\n", val, val);

    return EXIT_SUCCESS;
}
