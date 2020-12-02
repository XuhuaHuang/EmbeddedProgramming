/*****************************************************************//**
 * \file   mock_fn.cpp
 * \brief  contains function definitions for class in "mock.h"
 * 
 * \author Xuhua
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include "mock.h"

using namespace std;

void VideoGame::printInfo(void)
{
    cout << "\n[fn][VideoGame]Invoking Game::printInfo()" << endl;
    Game::printInfo();
    
    cout << "[fn][VideoGame]Genre = " << getGenre() << endl;
    cout << "[fn][VideoGame]Platform = " << getPlatform() << endl;

    return;
}

void BoardGame::printInfo()
{
    cout << "\n[fn][BoardGame]Invoking Game::printInfo()" << endl;
    Game::printInfo();

    cout << "[fn][BoardGame]Min age = " << getMinAge() << endl;
    cout << "[fn][BoardGame]Max number of players = " << getMaxNumPlayers() << endl;
}

Promotion::Promotion()
{
    VideoGame vg;
    setVideoGame(vg);

    BoardGame* ptrBG = new BoardGame;
    setBoardGame(ptrBG);
}

void Promotion::PrintInfo()
{
    cout << "\n[fn][Promotion]VideoGame on promotion: " << endl;
    getVideoGame().printInfo();
    
    cout << "[fn][Promotion]BoardGame on promotion: " << endl;
    getBoardGame()->printInfo();

    return;
}
