/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   October 19, 2020
 *********************************************************************/

#include "dealer.h"

int main(void)
{
    /*
    * Following the code of test case 1
    * variable name: test1, test1v2, testOL
    * line
    * testing:
    * 1) default & overloaded constructor
    * 2) set & get function
    * 3) printCard function
    * 4) allFaces & allSuits vectors
    */
    Card part1test1;
    std::cout << "Testing default constructor: \n\tFace:0\n\tSuit:0\n";
    std::cout << "The face is " << part1test1.getface() << "\n"
        << "The suit is " << part1test1.getsuit() << "\n";

    part1test1.printCard();

    std::cout << "\nA new card is created:\n";
    Card part1test2(12, 3);
    std::cout << "Testing overloaded constructor: ";
    std::cout << "\nWith the format Card variableName(int useriniface, int userinisuit): ";
    std::cout << "12 (face) and 3(suit)\n";
    part1test2.printCard();

    std::cout << "\nUsing for loops to declare the cards and print:\n" << "\n";
    for (int suit = 0; suit < 4; suit++)
    {
        for (int face = 0; face < 13; face++)
        {
            Card testOL(face, suit);
            testOL.printCard();
            //std::cout << "\n";
        }
    }
    // end of test case 1

    /*
    * Following the code of test case 2
    * variable name: part2test1
    * line 
    * testing:
    * 1) default constructor and printCards function
    * 2) shuffle()
    * 3) dealCard()
    */
    std::cout << "\nHere comes test cases for part 2:" << "\n";
    std::cout << "A new deck is created and printed." << "\n";
    Deck part2test1;
    part2test1.printCards();

    std::cout << "\nShuffling...";
    part2test1.shuffle();
    part2test1.printCards(); // verified shuffled

    std::cout << "\nTesting dealCard() and moreCards() function..." << "\n";
    std::cout << "Deal and print 52 cards as long as there are more cards" << "\n";
    while (part2test1.moreCards())
    {
        (part2test1.dealCard()).printCard();
        // Deck.dealCard() returns a variable of type Card
        // Card class grants the permission to printCard() function
    }
    // end of test case 2

    /*
    * Following the code of test case 3
    * variable name: part3deck, part3hand
    * line
    * testing:
    * 1) default constructor and printCards function
    * 2) shuffle()
    * 3) dealCard()
    */
    std::cout << "\nHere comes test cases for part 3:" << "\n";
    Deck part3deck;
    std::cout << "Creating a new deck and shuffling..." << "\n";
    part3deck.shuffle();

    Hand part3hand;

    std::cout << "5 cards should be distributed and printed:" << "\n";
    for (int deal = 0; deal < 5; deal++)
    {
        if (part3deck.moreCards())
        {
            Card cardToAdd = part3deck.dealCard();
            part3hand.addCard(cardToAdd);
        }
    }
    part3hand.printHandCards();
    // end of test case 3

    std::cin.get();
    return 0;
}
