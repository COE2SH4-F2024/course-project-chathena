#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
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
    srand(time(NULL));

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
    myPlayer = new Player(myGM, myFood);

    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    myFood->generatefood(playerPosList);
    
}
 
void GetInput(void)
{
    myGM->collectAsyncInput();
    // myGM->getInput();

    //debug
    char input = myGM->getInput();
    if(input == 'z'){
        myGM->incrementScore();
    }

    else if(input=='x'){
        myGM->setLoseFlag();
        myGM->setExitTrue();
    }
}

void RunLogic(void)
{
    
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}


void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    int boardX = myGM->getBoardSizeX(); 
    int boardY = myGM->getBoardSizeY();

    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    objPosArrayList* foodPos = myFood->getFoodPos();
    int playerSize = playerPosList->getSize();


    MacUILib_printf("##############################\n");

    for (int y = 1; y < boardY - 1; y++){
        for (int x = 0; x < boardX; x++){
            if (x == 0){
                MacUILib_printf("#");
            }
            else if (x >= 1 && x <= boardX - 2){
                bool flag = false;

                for(int i = 0; i < playerSize; i++){
                    objPos item = playerPosList->getElement(i);
                    if(item.pos->x == x && item.pos->y == y){
                        MacUILib_printf("%c", item.symbol);
                        flag = true;
                        break;
                    }
                }
                
                if(!flag){
                    if(x == foodPos->getHeadElement().pos->x && y == foodPos->getHeadElement().pos->y){
                        MacUILib_printf("%c", foodPos->getHeadElement().symbol);
                    }

                    else if(x == foodPos->getTailElement().pos->x && y == foodPos->getTailElement().pos->y){
                        MacUILib_printf("%c", foodPos->getTailElement().symbol);
                    }
                    else{
                        MacUILib_printf(" ");
                    }
                }
            }
            
            else if (x == boardX - 1){
                MacUILib_printf("#\n");
            }
        }
    }
    MacUILib_printf("##############################\n");
    MacUILib_printf("Player: ");
    // debugging
    // for (int i = 0; i < playerPosList->getSize(); i++) {
    //     objPos part = playerPosList->getElement(i);
    //     MacUILib_printf("[%d, %d, %c]\n", part.pos->x, part.pos->y, part.symbol);
    // }
    //     MacUILib_printf("\n");
    // MacUILib_printf("food[x, y] = [%d, %d], %c\n", foodPos->getHeadElement().pos->x, foodPos->getHeadElement().pos->y, foodPos->getHeadElement().symbol);
    
    MacUILib_printf("The score is: %d\n", myGM->getScore());
    
    if(myGM->getLoseFlagStatus() == true && myGM->getExitFlagStatus() == true){
        MacUILib_printf("You lost :(\n");
    }
    else if (myGM->getExitFlagStatus() == true){
        MacUILib_printf("You exited the game.\n");
    }
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
    delete myFood;

    MacUILib_uninit();
}