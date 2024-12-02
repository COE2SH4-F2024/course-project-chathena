#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "objPos.h"
#include "GameMechs.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    thisfoodRef = foodRef;
    playerPosList = new objPosArrayList();
    myDir = STOP;
    
    // more actions to be included

    //the starting position of the head
    objPos headPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');
    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
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
    // created temp objpos to calculate the new head posiition
    // used the the first element if the poslist as the head position
    
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();
    bool eatfood = false;

    objPos temphead = playerPosList->getHeadElement();

    // PPA3 Finite State Machine logic

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

    playerPosList->insertHead(temphead);

    // if self collision is detected, game ends and player loses
    if (checkSelfCollision() == true){
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }


    objPosArrayList* foodPos = thisfoodRef->getFoodPos();

    // if food position is equal to head position, snake eats food and points are given 
    for (int i = 0; i < foodPos->getSize(); i++){
        objPos myFood = foodPos->getElement(i);

        if(temphead.isPosEqual(&myFood)){
        eatfood = true;
            if(foodPos->getElement(i).getSymbol() == '$'){ //special food gets 10 points
                for (int k = 0; k < 10; k++){
                    mainGameMechsRef->incrementScore();
                }
            }
            else{
                mainGameMechsRef->incrementScore(); //normal food gets 1 point
            }
        }
    }

    if(eatfood){
        thisfoodRef->generatefood(playerPosList); //generates new position for food
    }
    else if(!eatfood){
        playerPosList->removeTail();
    }
}

bool Player::checkFoodConsumption(){

}

void Player::increasePlayerLength(){

}

bool Player::checkSelfCollision(){
    // if position of the snake head and snake body is equal, collision is detected
    for (int j = 3 ; j < playerPosList->getSize(); j++){
        if (((playerPosList->getElement(j).pos->x) == (playerPosList->getHeadElement().pos->x)) && ((playerPosList->getElement(j).pos->y) == (playerPosList->getHeadElement().pos->y))){
            return true;
        }
    }
    return false;
}
