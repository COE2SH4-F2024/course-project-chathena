#include "Food.h"
#include "MacUILib.h"
Food::Food()
{
    food.setObjPos(-10, -10, 'o');
}
Food::Food()
{
    food.setObjPos(-10, -10, 'o');
}

objPos Food::getFoodPos() const
{
    return food;
}
void Food::generatefood(objPos blockOff)
{
    // int i,j;
    // for(i = 0; i < 2; i++)
    // {
    //     int flag = 0;
    //     while(!flag)
    //     {
    //         foodPos.pos->x = rand() % (xRange - 1) + 1;
    //         itembin[i].y = rand() % (yRange -1) + 1;
    //         itembin[i].character = str[rand() % my_strlen(str)];
    //         flag = 1;
    //         if(itembin[i].x == player.x && itembin[i].y == player.y)
    //             {
    //                 flag = 0;

    //             }
    //         for(j = 0; j < i; j++)
    //         {
    //             if(itembin[i].x == itembin[j].x && itembin[i].y == itembin[j].y)
    //             {
    //                 flag = 0;
    //                 break;
    //             }
    //         }
    //     }
    // }
    
   
}