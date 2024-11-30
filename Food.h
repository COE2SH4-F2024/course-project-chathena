#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food{
    private:
        objPos food;
        int count;
    public:
        Food();
        ~Food();
        Food(const Food& other);
        Food& operator = (const Food& other);
        objPos getFoodPos() const;
        void generatefood(objPos blockOff, int boardX, int boardY, int playerX, int playerY);

};

#endif
