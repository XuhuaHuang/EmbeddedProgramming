#include <iostream>
#include <string>

using namespace std;

/*******************************
     GAME CLASS DEFINITION
*******************************/
class Game
{
public:
    Game();
    Game(string initName);
    void setName(string initName);
    string getName();
    void printInfo(void);
private:
    string name;
};

/**********************************
     GAME CLASS MEMBER FUNCTIONS
**********************************/
Game::Game()
{
    cout << "In Default Game Constructor" << endl;
    setName("Undefined");
}

Game::Game(string initName)
{
    cout << "In Overloaded Game Constructor" << endl;
    setName(initName);
}
// mutator
void Game::setName(string initName)
{
    name = initName;
}
// accessor
string Game::getName()
{
    return name;
}
// print
void Game::printInfo(void)
{
    cout << "Name = " << getName() << endl;
}


class VideoGame : public Game
{
public:
    VideoGame();
    VideoGame(string initName, string initPlatform, string initGenre = "Undefined");
    string getPlatform();
    void setPlatform(string initPlatform);
    string getGenre() { return genre; }
    void setGenre(string initGenre);
    void printInfo(void);
private:
    string genre;
    string platform;
};

/**********************************
     VIDEO GAME CLASS MEMBER FUNCTIONS
**********************************/
VideoGame::VideoGame()
{
    cout << "In Default Video Game Constructor" << endl;
    setGenre("Undefined");
    setPlatform("Undefined");
}

VideoGame::VideoGame(string initName, string initPlatform, string initGenre) : Game(initName)
{
    cout << "In Overloaded Game Constructor" << endl;
    setGenre(initGenre);
    setPlatform(initPlatform);
}
// mutator

void VideoGame::setGenre(string initGenre)
{
    genre = initGenre;
}
void VideoGame::setPlatform(string initPlatform)
{
    platform = initPlatform;
}
// accessor
string VideoGame::getPlatform()
{
    return platform;
}

// print
void VideoGame::printInfo(void)
{
    Game::printInfo();
    cout << "Genre = " << getGenre() << endl;
    cout << "Platform = " << getPlatform() << endl;
}
/* // class BoardGame and Pomotion are commented out
*  // missing function definition
class BoardGame : public Game
{
public:
    BoardGame();
    BoardGame(string initName, int initMinAge = 10, int initMaxNumPlayers = 4);
    void setminAge(int initMinAge);
    void setMaxNumPlayers(int initMaxNumPlayers);
    int getMinAge();
    int getMaxNumPlayers();
    void printInfo(void);
private:
    int minAge;
    int maxNumPlayers;
};

class Promotion
{
public:
    Promotion();
    ~Promotion();
    void setVideoGame(VideoGame initVideoGame);
    void setBoardGame(BoardGame* initBoardGame);
    VideoGame getVideoGame();
    BoardGame* getBoardGame();
    void PrintInfo(void);
private:
    VideoGame video;
    BoardGame* board;
};
*/

int main()
{





    return 0;
}
