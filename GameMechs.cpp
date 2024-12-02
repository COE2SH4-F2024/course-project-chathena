#include "GameMechs.h"
#include "MacUILib.h"
//defult constructor 
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false; 
    loseFlag = false;
    score = 0; 

    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false; 
    loseFlag = false;
    score = 0; 
    boardSizeX = boardX;
    boardSizeY = boardY; 

}

// destructor
GameMechs::~GameMechs()
{
    //no need, beacause we don't have a heap member  
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsyncInput()
{
    //checking if user inputed a charachter
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    //setting the exitFlag to true when the user pushes the space bar  
    if(input == ' '){
        exitFlag = true;
    } 
}
char GameMechs::getInput() const 
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
   score++; 
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}


// More methods should be added here