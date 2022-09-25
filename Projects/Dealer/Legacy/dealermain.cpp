#include "dealer.h"

using namespace std;

// 1879700 Xuhua Huang

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
    cout << "Testing default constructor: \n\tFace:0\n\tSuit:0\n";
    cout << "The face is " << part1test1.getface() << endl << "The suit is " << part1test1.getsuit() << endl;
    
    part1test1.printCard();
    
    cout << "\nA new card is created:\n";
    Card part1test2(12, 3);
    cout << "Testing overloaded constructor: ";
    cout << "\nWith the format Card variableName(int useriniface, int userinisuit): ";
    cout << "12 (face) and 3(suit)\n";
    part1test2.printCard();

    cout << "\nUsing for loops to declare the cards and print:\n" << endl;
    for (int suit = 0; suit < 4; suit++)
    {
        for (int face = 0; face < 13; face++)
        {
            Card testOL(face, suit);
            testOL.printCard();
            //cout << endl;
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
    cout << "\nHere comes test cases for part 2:" << endl;
    cout << "A new deck is created and printed." << endl;
    DeckofCard part2test1;
    part2test1.printCards();

    cout << "\nShuffling...";
    part2test1.shuffle();
    part2test1.printCards(); // verified shuffled

    cout << "\nTesting dealCard() and moreCards() function..." << endl;
    cout << "Deal and print 52 cards as long as there are more cards" << endl;
    while (part2test1.moreCards())
    {
        (part2test1.dealCard()).printCard();
        // DeckofCard.dealCard() returns a variable of type Card
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
    cout << "\nHere comes test cases for part 3:" << endl;
    DeckofCard part3deck;
    cout << "Creating a new deck and shuffling..." << endl;
    part3deck.shuffle();

    HandofCard part3hand;
    
    cout << "5 cards should be distributed and printed:" << endl;
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

    return 0;
}
