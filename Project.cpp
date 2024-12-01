#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include <time.h>
#include <stdlib.h>

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

    //seeding the random iteger generation function
    srand(time(NULL));

    //initial food position generation
    int boardX = myGM->getBoardSizeX(); 
    int boardY = myGM->getBoardSizeY();
    objPos initialplayerPos = myPlayer->getPlayerPos();
    myFood->generatefood(initialplayerPos, boardX, boardY);
    
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
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = myFood->getFoodPos();
    if(playerPos.pos->x == foodPos.pos->x && playerPos.pos->y == foodPos.pos->y)
    { 
        int boardX = myGM->getBoardSizeX(); 
        int boardY = myGM->getBoardSizeY();
        myFood->generatefood(playerPos, boardX, boardY);
    }
    

    
}


void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int boardX = myGM->getBoardSizeX(); 
    int boardY = myGM->getBoardSizeY(); 
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = myFood->getFoodPos();
    int playerX = playerPos.pos->x;
    int playerY = playerPos.pos->y;

    MacUILib_printf("##############################\n");
    for (int y = 1; y < boardY - 1; y++){
        for (int x = 0; x < boardX; x++){
            if (x == 0){
                MacUILib_printf("#");
            }
            if (x >= 1 && x <= boardX - 2){
                if (y == playerY && x == playerX){
                    MacUILib_printf("%c", playerPos.symbol);
                }
                else if(x == foodPos.pos->x && y == foodPos.pos->y){
                MacUILib_printf("%c", foodPos.symbol);
            }
                else{
                    MacUILib_printf(" ");
                }
            }
            if (x == boardX - 1){
                MacUILib_printf("#\n");
            }
        }
    }
    MacUILib_printf("##############################\n");
    MacUILib_printf("player[x, y] = [%d, %d], %c", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    MacUILib_printf("food[x, y] = [%d, %d], %c", foodPos.pos->x, foodPos.pos->y, foodPos.symbol);

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
