#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food{
    private:
        objPos food;
        objPosArrayList* foodBucket;

    public:
        Food();
        ~Food();
        
        objPosArrayList* getFoodPos() const;
        void generatefood(objPosArrayList* blockOff);

};

#endif
