/*****************************************************************//**
 * \file   dealer.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   October 19, 2020
 *********************************************************************/

#include <algorithm>
#include <random>
#include "dealer.h"

void Card::fillVector(void)
{
    // filling the allSuits vector
    allSuits.push_back("clubs");
    allSuits.push_back("diamonds");
    allSuits.push_back("hearts");
    allSuits.push_back("spades");

    //filling the allFaces vector
    allFaces.push_back("ace");
    allFaces.push_back("two");
    allFaces.push_back("three");
    allFaces.push_back("four");
    allFaces.push_back("five");
    allFaces.push_back("six");
    allFaces.push_back("seven");
    allFaces.push_back("eight");
    allFaces.push_back("nine");
    allFaces.push_back("ten");
    allFaces.push_back("Jack");
    allFaces.push_back("Queen");
    allFaces.push_back("King");

    return;
}

Card::Card() // default Card constructor
{
    setface(0);
    setsuit(0);
    fillVector();
}

Card::Card(int useriniface, int userinisuit) // overloaded Card constructor with two arguments
{
    setface(useriniface);
    setsuit(userinisuit);
    fillVector();
}

void Card::printCard() // print the card in format face of suit
{
    std::cout << "Card is " << allFaces.at(getface()) << " of " << allSuits.at(getsuit()) << "\n";

    return;
}

// functions inside Deck class are listed below:
Deck::Deck() // default constructor for the Deck class
{
    for (int suit = 0; suit < 4; suit++)
    {
        for (int face = 0; face < 13; face++)
        {
            Card newCard(face, suit);
            deck.push_back(newCard); // vector<Card> deck "deck" is the name
        }
    }
    setcurrentCard(0);
}

void Deck::nextCard()
{
    setcurrentCard(getcurrentCard() + 1); // increment currentCard and overwrite using set function
    //cout << "\nVariable currenCard has been incremented." << "\n";

    return;
}

void Deck::shuffle()
{
    random_shuffle(deck.begin(), deck.end()); // have access to vector<Card> deck since in the class
    std::cout << "\nThe deck is now shuffled!" << "\n";

    return;
}

Card Deck::dealCard()
{
    Card cardToReturn = deck.at(getcurrentCard()); // deck is a vector of type 'Card'
    // require same type variable to obtain the content
    nextCard();

    return cardToReturn;
}

bool Deck::moreCards()
{
    bool ifMoreCard = false; // default state
    
    if (getcurrentCard() < 52)
        ifMoreCard = true;

    return ifMoreCard;
}

void Deck::printCards()
{
    std::vector<Card>::iterator itercard; // the content of the iterator is an object of type/class "Card"
    // 'itecard' is an iterator of "vector<Card> deck"

    for (itercard = deck.begin(); itercard < deck.end(); itercard++)
    {
        (*itercard).printCard();
    }

    return;
}

// functions inside Hand class are listed below:
void Hand::addCard(Card cardToAdd)
{
    hand.push_back(cardToAdd); // 'vector<Card> hand' of type Card
    // add a card to vector<Card> hand using push_back(element)

    return;
}

void Hand::printHandCards(void)
{
    std::vector<Card>::iterator iterHandCard; // using iterator to loop through vector<Card> hand
    for (iterHandCard = hand.begin(); iterHandCard < hand.end(); iterHandCard++)
    {
        (*iterHandCard).printCard(); // print in format: face of suit
        // (*iterHandCard) contains the content of type 'Card'. Therefore, granted access to printCard()
    }

    return;
}
