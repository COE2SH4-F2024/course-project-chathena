#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include <stdlib.h>
#include <time.h>

Food::Food()
{
    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    delete foodBucket;    
}

void Food::generatefood(objPosArrayList* blockOff)
{   
    bool valid = true;
    GameMechs myGM;
    objPos Food; 

    for (int k = 0; k < 5; k++){
        foodBucket->removeTail();
    }



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
                }
            }

            for (int j = 0; j < foodBucket->getSize(); j++){
                objPos thisFood = foodBucket->getElement(j);
                if(Food.isPosEqual(&thisFood)){
                    valid = false;
                }
            }

        }while (!valid);

        foodBucket->insertHead(Food);
    }
    
    for (int i = 0; i < 2; i++){
        do{
            valid = true;

            int newX = rand() % (myGM.getBoardSizeX() - 2) + 1;
            int newY = rand() % (myGM.getBoardSizeY() - 2) + 1;

            Food.setObjPos(newX, newY, '$');

            for (int j = 0; j < foodBucket->getSize(); j++){
                objPos headelement = foodBucket->getHeadElement();
                if(Food.isPosEqual(&headelement)){
                    valid = false;
                }
            }

        }while (!valid);

        foodBucket->insertHead(Food);
    }
}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}


