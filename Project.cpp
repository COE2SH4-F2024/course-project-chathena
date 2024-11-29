#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer;
GameMechs *myGM;
Food *food;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    food = 
    myPlayer = new Player(myGM);
  
}

void RunLogic(void)
{
    myPlayer->movePlayer();
}
void GetInput(void)
{
    myGM->collectAsyncInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int boardX = myGM->getBoardSizeX(); 
    int boardY = myGM->getBoardSizeY(); 
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = food->getFoodPos();
    
    for (int i = 0; i < boardY; i++)
    {
        for (int j = 0; j < boardX; j++)
        {
            if ((i == 0) || (i == boardY - 1) || (j == 0) || (j == boardX - 1))
            {
                MacUILib_printf("=");
            }
            else if (i == playerPos.pos->y && j == playerPos.pos->x)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            
            else
            {
                int k,flag = 0;
                for(k = 0; k < itembin[k]; k++)
                {
                    if(itembin[k].x == j && itembin[k].y == i)
                    {
                        MacUILib_printf("%c", itembin[k].character);
                        flag = 1;
                        break;
                    }
                } 
                if(!flag)
                    MacUILib_printf(" ");
            }


        }
    }
    MacUILib_printf("\n");
    MacUILib_printf("player[x, y] = [%d, %d], %c", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
