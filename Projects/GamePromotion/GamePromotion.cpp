/*****************************************************************//**
 * \file   mock_fn.cpp
 * \brief  contains function definitions for class in "GamePromotion.hpp"
 *
 * \author Xuhua
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include "GamePromotion.hpp"

void VideoGame::printInfo(void)
{
    std::cout << "\n[fn][VideoGame]Invoking Game::printInfo()" << "\n";
    Game::printInfo();

    std::cout << "[fn][VideoGame]Genre = " << getGenre() << "\n";
    std::cout << "[fn][VideoGame]Platform = " << getPlatform() << "\n";

    return;
}

void BoardGame::printInfo()
{
    std::cout << "\n[fn][BoardGame]Invoking Game::printInfo()" << "\n";
    Game::printInfo();

    std::cout << "[fn][BoardGame]Min age = " << getMinAge() << "\n";
    std::cout << "[fn][BoardGame]Max number of players = " << getMaxNumPlayers() << "\n";
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
    std::cout << "\n[fn][Promotion]VideoGame on promotion: " << "\n";
    getVideoGame().printInfo();

    std::cout << "[fn][Promotion]BoardGame on promotion: " << "\n";
    getBoardGame()->printInfo();

    return;
}
