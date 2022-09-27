/*****************************************************************//**
 * \file   TwelveDays.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   September 27, 2022
 *********************************************************************/

#include <iostream>
#include <vector>
#include <string>

namespace data {
    const std::vector<std::string> days{
        "first", "second", "third", "fourth",
        "fifth", "sixth", "seventh", "eighth",
        "ninth", "tenth", "eleventh", "twelfth"
    };
}

int main(void) {
    std::ios::sync_with_stdio(false);
    for (int days = 0; days < 12; ++days) {
        std::cout << "\nOn the " << data::days[days] << " day of Christmas, "
            << "my true love sent to me : " << "\n";

        switch (days) {
        case 11:
            std::cout << "twelve Drummers Drumming" << "\n";
        case 10:
            std::cout << "eleven Pipers Piping" << "\n";
        case 9:
            std::cout << "ten Lords a Leaping" << "\n";
        case 8:
            std::cout << "nine Ladies Dancing" << "\n";
        case 7:
            std::cout << "eight Maids a Milking" << "\n";
        case 6:
            std::cout << "seven Swans a Swimming" << "\n";
        case 5:
            std::cout << "six Geese a Laying" << "\n";
        case 4:
            std::cout << "five Golden Rings" << "\n";
        case 3:
            std::cout << "four Calling Birds" << "\n";
        case 2:
            std::cout << "three French Hens" << "\n";
        case 1:
            std::cout << "two turtle doves" << "\n";
        case 0:
            std::cout << "a partridge in a pear tree" << "\n";
        }
    }

    return 0;
}
