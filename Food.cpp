#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <stdlib.h>
#include <time.h>

Food::Food()
{
    food.setObjPos(-10, -10, 'o');
}
Food::~Food()
{
    
}
Food::Food(const Food& other)
{

}
Food& Food::operator = (const Food& other)
{
    if(this == &other)
        return *this;
    food = other.food;
    count = other.count;
    return *this;
}
objPos Food::getFoodPos() const
{
    return food;
}
void Food::generatefood(objPos blockOff, int boardX, int boardY)
{   
    bool valid = false ;
    while(!valid)
    {
        int newX = rand() % (boardX - 2) + 1;
        int newY = rand() % (boardY - 2) + 1;

        if(newX == blockOff.pos->x && newY == blockOff.pos->y)
            continue;
        food.setObjPos(newX, newY, 'o');
        valid = true;
            
    }
    
    
   
}
