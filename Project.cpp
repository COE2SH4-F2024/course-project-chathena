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
Food *myFood;


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
    myFood = new Food();
    myPlayer = new Player(myGM);
  
}
 
void GetInput(void)
{
    myGM->collectAsyncInput();
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
}


void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int boardX = myGM->getBoardSizeX(); 
    int boardY = myGM->getBoardSizeY(); 
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = food->getFoodPos();

    //Cheryl's drawscreen
    MacUILib_printf("##############################\n");
   for (int y = 1; y < boardY - 1; y++){
        for (int x = 0; x < boardX; x++){
            if (x == 0){
                MacUILib_printf("#");
            }
            if (x >= 1 && x <= boardX - 2){
                if (y == playerPos.pos->y && x == playerPos.pos->x){
                    MacUILib_printf("%c", playerPos.symbol);
                }
                else if(y == foodPos.pos->x && x == foodPos.pos->y){
                MacUILib_printf("%c", foodPos.symbol);
            }
                else{
                    MacUILib_printf(" ");
                }
            }
            if (x == boardX - 1){
                MacUILib_printf("#\n");
            }
             
            // else{
            //     int k,flag = 0;
            //     for(k = 0; k < itembin[k]; k++)
            //     {
            //         if(itembin[k].x == j && itembin[k].y == i)
            //         {
            //             MacUILib_printf("%c", itembin[k].character);
            //             flag = 1;
            //             break;
            //         }
            //     }

        }
    }
   MacUILib_printf("##############################\n");
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
