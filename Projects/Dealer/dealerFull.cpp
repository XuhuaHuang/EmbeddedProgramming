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
			cout << endl;
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
	cout << "Card is " << allFaces.at(getface()) << " of " << allSuits.at(getsuit()) << endl;

	return;
}

// functions inside DeckofCard class are listed below:
DeckofCard::DeckofCard() // default constructor for the DeckofCard class
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

void DeckofCard::nextCard()
{
	setcurrentCard(getcurrentCard() + 1); // increment currentCard and overwrite using set function
	//cout << "\nVariable currenCard has been incremented." << endl;

	return;
}

void DeckofCard::shuffle()
{
	random_shuffle(deck.begin(), deck.end()); // have access to vector<Card> deck since in the class
	cout << "\nThe deck is now shuffled!" << endl;

	return;
}

Card DeckofCard::dealCard()
{
	Card cardToReturn = deck.at(getcurrentCard()); // deck is a vector of type 'Card'
	// require same type variable to obtain the content
	nextCard();

	return cardToReturn;
}

bool DeckofCard::moreCards()
{
	bool ifMoreCard = false; // default state
	
	if (getcurrentCard() < 52)
		ifMoreCard = true;

	return ifMoreCard;
}

void DeckofCard::printCards()
{
	vector<Card>::iterator itercard; // the content of the iterator is an object of type/class "Card"
	// 'itercard' is an iterator of "vector<Card> deck"

	for (itercard = deck.begin(); itercard < deck.end(); itercard++)
	{
		(*itercard).printCard();
	}

	return;
}

// functions inside HandofCard class are listed below:
void HandofCard::addCard(Card cardToAdd)
{
	hand.push_back(cardToAdd); // 'vector<Card> hand' of type Card
	// add a card to vector<Card> hand using push_back(element)

	return;
}

void HandofCard::printHandCards(void)
{
	vector<Card>::iterator iterHandCard; // using iterator to loop through vector<Card> hand
	for (iterHandCard = hand.begin(); iterHandCard < hand.end(); iterHandCard++)
	{
		(*iterHandCard).printCard(); // print in format: face of suit
		// (*iterHandCard) contains the content of type 'Card'. Therefore, granted access to printCard()
	}

	return;
}
