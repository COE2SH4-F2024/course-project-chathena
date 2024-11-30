#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = thisGMRef->getBoardSizeX() / 2;
    playerPos.pos->y = thisGMRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    // no "new" bc no heap member
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
        char input = mainGameMechsRef->getInput();
        switch(input){
            case 'w':
            case 'W': 
                if (myDir != DOWN && myDir != UP){
                    myDir = UP;
                }
                break;

            case 's':
            case 'S':
                if (myDir != UP && myDir != DOWN){
                    myDir = DOWN;                    
                }
                break;

            case 'a':
            case 'A':
                if (myDir != RIGHT && myDir != LEFT){
                    myDir = LEFT;
                }
                break;

            case 'd':
            case 'D':
                if(myDir != LEFT && myDir != RIGHT){
                    myDir = RIGHT; 
                }
                break;

            default:
                break;
        }        
}

void Player::movePlayer()
{

    // PPA3 Finite State Machine logic
    if (myDir == UP){
        playerPos.pos->y--;
        if (playerPos.pos->y <= 0){
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;  
        }
    }

    else if (myDir == DOWN){
        playerPos.pos->y++;
        if (playerPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2){
            playerPos.pos->y = 1;
        }
    }

    else if (myDir == LEFT){
        playerPos.pos->x--;
        if (playerPos.pos->x <= 0){
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
    }

    else if (myDir == RIGHT){
        playerPos.pos->x++;
        if (playerPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2){
            playerPos.pos->x = 1;
        }
    } 
}

// More methods to be added