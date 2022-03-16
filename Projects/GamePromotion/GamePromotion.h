/*****************************************************************//**
 * \file   mock.h
 * \brief  contains class declarations, in-line functions
 *
 * \author Xuhua
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*******************************
*	 GAME CLASS DEFINITION     *
********************************/
class Game
{
public:
	Game() : name("Undefined") { cout << "[DFCONST]Game" << endl; }
	Game(string initName) : name(initName) { cout << "[OLCONST]Game" << endl; }

	void setName(string initName) { this->name = initName; }
	string getName() { return name; }

	void printInfo(void) { cout << "[fn][Game]Name = " << getName() << endl; };

private:
	string name;
};

/************************************
*	 VIDEOGAME CLASS DEFINITION     *
*************************************/
class VideoGame : public Game
{
public:
	VideoGame() : genre("Undefined"), platform("Undefined") { cout << "[DECONST]VideoGame" << endl; }

	VideoGame(string initName, string initPlatform, string initGenre = "Undefined")
		: Game(initName), platform(initPlatform), genre(initGenre)
	{
		cout << "\n[OLCONST]VideoGame" << endl;
	}

	string getPlatform() { return platform; }
	void setPlatform(string initPlatform) { platform = initPlatform; }
	string getGenre() { return genre; }
	void setGenre(string initGenre) { genre = initGenre; }

	void printInfo(void); // defined

private:
	string genre;
	string platform;
};

/************************************
*	 BOARDGAME CLASS DEFINITION     *
*************************************/
class BoardGame : public Game
{
public:
	BoardGame() : minAge(18), maxNumPlayers(10) { cout << "[DECONST]BoardGame" << endl; }

	BoardGame(string initName, int initMinAge = 10, int initMaxNumPlayers = 4)
		: Game(initName), minAge(initMinAge), maxNumPlayers(initMaxNumPlayers)
	{
		cout << "[OLCONST]VideoGame" << endl;
	}

	void setminAge(int initMinAge) { minAge = initMinAge; }
	int getMinAge() { return minAge; }
	void setMaxNumPlayers(int initMaxNumPlayers) { maxNumPlayers = initMaxNumPlayers; }
	int getMaxNumPlayers() { return maxNumPlayers; }

	void printInfo(void); // defined

private:
	int minAge;
	int maxNumPlayers;
};

/************************************
*	 PROMOTION CLASS DEFINITION     *
*************************************/
class Promotion
{
public:
	Promotion();
	~Promotion() { delete board; }

	void setVideoGame(VideoGame initVideoGame) { video = initVideoGame; }
	VideoGame getVideoGame() { return video; }
	void setBoardGame(BoardGame* initBoardGame) { board = initBoardGame; }
	BoardGame* getBoardGame() { return board; }

	void PrintInfo(void);

private:
	VideoGame video;
	BoardGame* board;
};
