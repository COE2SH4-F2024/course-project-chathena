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

    // ?????? IDK ???????
    foodBucket->removeTail();
    foodBucket->removeTail();

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
    }while (!valid);

    foodBucket->insertHead(Food);

    do{
        valid = true;

        int newX = rand() % (myGM.getBoardSizeX() - 2) + 1;
        int newY = rand() % (myGM.getBoardSizeY() - 2) + 1;

        Food.setObjPos(newX, newY, '$');

        objPos headelement = foodBucket->getHeadElement();
            if(Food.isPosEqual(&headelement)){
                valid = false;
        }

    }while (!valid);

    foodBucket->insertTail(Food);
}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}


    // while(!valid)
    // {
    //     int newX = rand() % (myGM.getBoardSizeX() - 2) + 1;
    //     int newY = rand() % (myGM.getBoardSizeY() - 2) + 1;

    //     for(int i = 0; i < blockOff->getSize(); i++)
    //     {
    //         objPos current = blockOff->getElement(i);
    //         if (Food.isPosEqual(&current)){
    //             valid = false;
    //         }   
    //     } 
        
    //     food.setObjPos(newX, newY, 'o');
    // }
    
    // foodBucket->insertHead(Food);

    //  while(!valid)
    // {
    //     int newX = rand() % (myGM.getBoardSizeX() - 2) + 1;
    //     int newY = rand() % (myGM.getBoardSizeY() - 2) + 1;

    //     objPos current = foodBucket->getHeadElement();
    //     if (Food.isPosEqual(&current)){
    //         valid = false;
    //     }     

    //     food.setObjPos(newX, newY, '$');  
    // }
    // foodBucket->insertTail(Food);  


