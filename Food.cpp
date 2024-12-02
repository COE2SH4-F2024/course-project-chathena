#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include <stdlib.h>
#include <time.h>
//constructor 
Food::Food()
{
    foodBucket = new objPosArrayList();
}
//destructor
Food::~Food()
{
    delete foodBucket;    
}

void Food::generatefood(objPosArrayList* blockOff)
{   
    bool valid = true;
    GameMechs myGM;
    objPos Food; 

    // deletes current food on DrawScreen after collision occurs with snake and food
    while (foodBucket->getSize() > 0){
        foodBucket->removeTail();
    }


    // generating the regular food position (o) and ensuring it doesn't interrupt
    // the player and the other generated foods 
    for (int i = 0; i < 3; i++){
        do{
            valid = true;

            int newX = rand() % (myGM.getBoardSizeX() - 2) + 1;
            int newY = rand() % (myGM.getBoardSizeY() - 2) + 1;

            Food.setObjPos(newX, newY, 'o');

            for (int i = 0; i < blockOff->getSize(); i++){
                objPos current = blockOff->getElement(i);
                if(Food.isPosEqual(&current)){
                    valid = false;
                    break;
                }
            }

            for (int j = 0; j < foodBucket->getSize(); j++){
                objPos thisFood = foodBucket->getElement(j);
                if(Food.isPosEqual(&thisFood)){
                    valid = false;
                    break;
                }
            }

        }while (!valid);

        foodBucket->insertHead(Food);
    }
    //generating the super food position ($) and ensuring it doesn't interrupt
    // the player and the other generated foods
    for (int i = 0; i < 2; i++){
        do{
            valid = true;

            int newX = rand() % (myGM.getBoardSizeX() - 2) + 1;
            int newY = rand() % (myGM.getBoardSizeY() - 2) + 1;

            Food.setObjPos(newX, newY, '$');

            for (int i = 0; i < blockOff->getSize(); i++){
                objPos current = blockOff->getElement(i);
                if(Food.isPosEqual(&current)){
                    valid = false;
                    break;
                }
            }

            for (int j = 0; j < foodBucket->getSize(); j++){
                objPos thisFood = foodBucket->getElement(j);
                if(Food.isPosEqual(&thisFood)){
                    valid = false;
                    break;
                }
            }

        }while (!valid);

        foodBucket->insertHead(Food);
    }
}
// receive position of food
objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}


