#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
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
void Food::generatefood(objPos blockOff, int boardX, int boardY, int playerX, int playerY)
{   
    bool valid = false ;
    while(!valid)
    {
        int newX = rand() % (boardX - 1) + 1;
        int newY = rand() % (boardY - 1) + 1;

        if(newX == playerX && newY == playerY)
            continue;
        food.setObjPos(newX, newY, 'o');
        valid = true;
            
    }
    
    
   
}
