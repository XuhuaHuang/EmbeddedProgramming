/*****************************************************************//**
 * \file   mock.h
 * \brief  contains class declarations, in-line functions
 *
 * \author Xuhua
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <string>

/*******************************
*    GAME CLASS DEFINITION     *
********************************/
class Game
{
public:
    Game() : name("Undefined") { std::cout << "[DFCONST]Game" << "\n"; }
    Game(std::string initName) : name(initName) { std::cout << "[OLCONST]Game" << "\n"; }

    void setName(std::string initName) { this->name = initName; }
    std::string getName() { return name; }

    void printInfo(void) { std::cout << "[fn][Game]Name = " << getName() << "\n"; };

private:
    std::string name;
};

/************************************
*    VIDEOGAME CLASS DEFINITION     *
*************************************/
class VideoGame : public Game
{
public:
    VideoGame() : genre("Undefined"), platform("Undefined") { std::cout << "[DECONST]VideoGame" << "\n"; }

    VideoGame(std::string initName, std::string initPlatform, std::string initGenre = "Undefined")
        : Game(initName), platform(initPlatform), genre(initGenre)
    {
        std::cout << "\n[OLCONST]VideoGame" << "\n";
    }

    std::string getPlatform() { return platform; }
    void setPlatform(std::string initPlatform) { platform = initPlatform; }
    std::string getGenre() { return genre; }
    void setGenre(std::string initGenre) { genre = initGenre; }

    void printInfo(void); // defined

private:
    std::string genre;
    std::string platform;
};

/************************************
*    BOARDGAME CLASS DEFINITION     *
*************************************/
class BoardGame : public Game
{
public:
    BoardGame() : minAge(18), maxNumPlayers(10) { std::cout << "[DECONST]BoardGame" << "\n"; }

    BoardGame(std::string initName, int initMinAge = 10, int initMaxNumPlayers = 4)
        : Game(initName), minAge(initMinAge), maxNumPlayers(initMaxNumPlayers)
    {
        std::cout << "[OLCONST]VideoGame" << "\n";
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
*    PROMOTION CLASS DEFINITION     *
*************************************/
class Promotion
{
public:
    Promotion();
    ~Promotion() {
        delete board;
        board = nullptr;
    }

    void setVideoGame(VideoGame initVideoGame) { video = initVideoGame; }
    VideoGame getVideoGame() { return video; }
    void setBoardGame(BoardGame* initBoardGame) { this->board = initBoardGame; }
    BoardGame* getBoardGame() { return this->board; }

    void PrintInfo(void);

private:
    VideoGame video;
    BoardGame* board;
};
