/*****************************************************************//**
 * \file   stringNotes.cpp
 * \brief  lab on strings in C++
 *
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include <iostream>
#include <string>

int main(void)
{
    // requirement 1
    std::string userInput1;
    std::cout << "Please enter your favourite idiom:" << "\n";
    getline(std::cin, userInput1);
    std::cout << "The sentence you just entered is: " + userInput1 << "\n";  // for testing purpose only

    std::string dogName;
    std::cout << "Please enter your dog's name. We promise we won't do any harm to your loved ones." << "\n";
    std::cin.ignore() >> dogName;

    std::string dogBreed;
    std::cout << "Do you mind telling us its breed?" << "\n";
    std::cin.ignore() >> dogBreed;

    std::cout << "Great! " + dogName + " is of breed " + dogBreed << "\n";
    std::cout << "This is the end of requirement 1." << "\n";

    // requirement 2 find and erase
    std::string fixedStr = "she sells seashells from the sea shore.";

    size_t search = fixedStr.find('s', 0);

    while (search != std::string::npos)
    {
        fixedStr.erase(search, 1);
        search = fixedStr.find('s', 0);
        std::cout << "It is now: " + fixedStr << "\n"; // printing the lines  to see one "s" less each line
    } // end while


    // requirement 3: insert letter "q" to the center of any word
    std::cout << "\nWarning! I am going to insert letter \"q\" to the center of your std::string." << "\n";
    std::string userInput2;
    std::cin >> userInput2;
    int strlength = userInput2.length();
    std::cout << "\nThe size of the word you just entered is: " << strlength << "\n"; // for testing purpose

    int halflength = strlength / 2;
    if (halflength % 2 == 1)
        userInput2.insert(halflength + 1, 1, 'q');
    else if (halflength % 2 == 0)
        userInput2.insert(halflength, 1, 'q');

    std::cout << "New \"word\" is: " << userInput2 << "\n";

    std::cout << "\nHow many \"q\"s do you want to insert to the center of the word?" << "\n";
    int numq = 0;
    std::cin >> numq;
    userInput2.insert(halflength, numq - 1, 'q'); // there was already one q existed
    std::cout << "Now the new \"word\" is: " << userInput2 << "\n";

    // requirement 5 using iterators
    std::cout << "Using iterators..." << "\n";
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::cout << "The original alphabetical std::string is: " << alpha << "\n";

    std::string::iterator iteralpha; // define an iterator object

    for (int x = 0; x <= (int)alpha.length(); x++) // forstd::cing it to of type int
    {
        for (iteralpha = alpha.begin(); iteralpha < alpha.begin() + x; iteralpha++)
        {
            std::cout << *iteralpha;
        }
        std::cout << "\n";
    }


    // requirement 6 comparing std::strings
    std::cout << "Comparing std::string..." << "\n";
    std::string fruit1, fruit2, fruit3;

    std::cout << "Please enter three different fruits: " << "\n";
    std::cout << "\nThe first one:\n";
    std::cin >> fruit1;
    std::cout << "The second one:\n";
    std::cin >> fruit2;
    std::cout << "The second one:\n";
    std::cin >> fruit3;

    if ((fruit1 < fruit2) && (fruit1 < fruit3)) // fruit1 comes first
    {
        std::cout << "\n" << fruit1 << " comes first alphabetically." << "\n";

        if (fruit2 < fruit3)
            std::cout << fruit3 << " comes least alphabetically." << "\n";
        else // fruit3 < fruit2
            std::cout << fruit2 << " comes least alphabetically." << "\n";
    }
    else if ((fruit2 < fruit1) && (fruit2 < fruit3)) // fruit2 comes first
    {
        std::cout << "\n" << fruit2 << " comes first alphabetically." << "\n";

        if (fruit1 < fruit3)
            std::cout << fruit3 << " comes least alphabetically." << "\n";
        else // fruit3 < fruit1
            std::cout << fruit1 << " comes least alphabetically." << "\n";
    }
    else // fruit3 comes first
    {
        std::cout << "\n" << fruit3 << " comes first alphabetically." << "\n";

        if (fruit1 < fruit2)
            std::cout << fruit2 << " comes least alphabetically." << "\n";
        else // fruit2 < fruit1
            std::cout << fruit1 << " comes least alphabetically." << "\n";
    }

    return 0;
}