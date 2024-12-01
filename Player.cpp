#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "objPos.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    myDir = STOP;
    

    // more actions to be included
    //the starting position of the head
    objPos headPos(thisGMRef->getBoardSizeX() / 2, thisGMRef->getBoardSizeY() / 2, '@');

    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    // no "new" bc no heap member
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the player position arrray list
    return playerPosList;
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
    // Iteration 3:

    //create temp objpos to calcualate the new head posiition
    // use the the first element if the poslist as the head position
    objPos temphead = playerPosList->getHeadElement();
    int boardY = mainGameMechsRef->getBoardSizeY();
    int boardX = mainGameMechsRef->getBoardSizeX();
    Food* myFood;
    objPos foodPos = myFood->getFoodPos();

    if (myDir == UP){
        temphead.pos->y--;
        if (temphead.pos->y <= 0){
            temphead.pos->y = boardY - 2;  
        }
    }

    else if (myDir == DOWN){
        temphead.pos->y++;
        if (temphead.pos->y > boardY - 2){
            temphead.pos->y = 1;
        }
    }

    else if (myDir == LEFT){
        temphead.pos->x--;
        if (temphead.pos->x <= 0){
            temphead.pos->x = boardX - 2;
        }
    }

    else if (myDir == RIGHT){
        temphead.pos->x++;
        if (temphead.pos->x > boardX - 2){
            temphead.pos->x = 1;
        }
    } 

    
    // if(temphead.pos->x == foodPos.pos->x && temphead.pos->y == foodPos.pos->y){
    //     myFood->generatefood(temphead, boardX, boardY);
    // }
    // playerPosList->insertHead(temphead);
    // if(temphead.isPosEqual(&foodPos)){
    //    myFood->generatefood(temphead, boardX, boardY);
    // else{
    //     playerPosList->removeTail();
        
    // } 

} 

// More methods to be added