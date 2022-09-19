#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <windows.h>
#include <random>

using namespace std;

// Xuhua Huang 1879700

class Card
{
private:
    int face;
    int suit;

    // vectors are initialized later in fillVector() function
    vector <string> allFaces;
    vector <string> allSuits;

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

class DeckofCard
{
private:
    vector<Card> deck;
    int currentCard;

public:
    // get and set function for int currentCard
    int getcurrentCard() { return currentCard; }
    void setcurrentCard(int usercurrentCard) { currentCard = usercurrentCard; }

    // default and overloaded constructor:
    DeckofCard();

    // other function prototype
    void nextCard();
    void shuffle();
    Card dealCard(); // this function returns a variable of type 'Card' as defined above
    bool moreCards();
    void printCards();
};

class HandofCard
{
private:
    vector<Card> hand;

public:
    void addCard(Card cardToAdd);
    void printHandCards(void);
};
