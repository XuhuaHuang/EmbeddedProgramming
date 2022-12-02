/*****************************************************************//**
 * \file   dealer.h
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   October 19, 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include <vector>

class Card
{
private:
    int face;
    int suit;

    // vectors are initialized later in fillVector() function
    std::vector<std::string> allFaces;
    std::vector<std::string> allSuits;

public:
    // get and set functions are done with one line functions
    // get functions
    int getface() { return face; }
    int getsuit() { return suit; }
    // set functions
    void setface(int userface) { face = userface; }
    void setsuit(int userface) { suit = userface; }

    // other functions prototypes
    void fillVector(void); // push_back(element) to allFaces and allSuits

    // default and overload constructors:
    Card();
    Card(int useriniface, int userinisuit);

    // print card function prototype 
    void printCard();
};

class Deck
{
private:
    std::vector<Card> deck;
    int currentCard;

public:
    // get and set function for int currentCard
    int getcurrentCard() { return currentCard; }
    void setcurrentCard(int usercurrentCard) { currentCard = usercurrentCard; }

    // default and overloaded constructor:
    Deck();

    // other function prototype
    void nextCard();
    void shuffle();
    Card dealCard(); // this function returns a variable of type 'Card' as defined above
    bool moreCards();
    void printCards();
};

class Hand
{
private:
    std::vector<Card> hand;

public:
    Hand() = default;
    virtual ~Hand() = default;

    void addCard(Card cardToAdd);
    void printHandCards(void);
};
