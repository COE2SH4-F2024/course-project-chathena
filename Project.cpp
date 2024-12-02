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

// declaring global pointers
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
    srand(time(NULL)); // Seeding the random integer generation function with current time

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

    // initializing the global pointers
    myGM = new GameMechs();
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);

    // generating the initial random food positions at the start of the game 
    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    myFood->generatefood(playerPosList);
    
}
 
void GetInput(void) // collect input
{
    myGM->collectAsyncInput();
}

void RunLogic(void) // updating player interaction
{
    
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
}


void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    //getting the size of the board and storing it in a local variable to reduce the number of times the function is called
    int boardX = myGM->getBoardSizeX(); 
    int boardY = myGM->getBoardSizeY();

    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    objPosArrayList* foodPos = myFood->getFoodPos();
    int playerSize = playerPosList->getSize();
    int foodSize = foodPos->getSize();

    MacUILib_printf("##############################\n"); // creating border

    for (int y = 1; y < boardY - 1; y++){
        for (int x = 0; x < boardX; x++){
            if (x == 0){
                MacUILib_printf("#");
            }
            else if (x >= 1 && x <= boardX - 2){
                bool flag = false;

                // print player position
                for(int i = 0; i < playerSize; i++){
                    objPos item = playerPosList->getElement(i);
                    if(item.pos->x == x && item.pos->y == y){
                        MacUILib_printf("%c", item.symbol);
                        flag = true;
                        break;
                    }
                }

                // print food position
                for(int i = 0; i < foodSize; i++){
                    objPos item = foodPos->getElement(i);
                    if(item.pos->x == x && item.pos->y == y){
                        MacUILib_printf("%c", item.symbol);
                        flag = true;
                        break;
                    }
                }
                
                if(!flag){
                    MacUILib_printf(" ");  // print empty space
                }
            }
            
            else if (x == boardX - 1){
                MacUILib_printf("#\n"); 
            }
        }
    } 
    MacUILib_printf("##############################\n"); // creating border

    MacUILib_printf("The score is: %d\n", myGM->getScore()); // print updated score 
    MacUILib_printf("\n");

    // instructions to the game
    MacUILib_printf("Press 'W','S','A','D' to move the snake UP, DOWN, LEFT or RIGHT (respectively).\n");
    MacUILib_printf("Eat the food on the game board to grow your snake!\n");
    MacUILib_printf("Avoid colliding into the body of your snake, or you'll LOSE :(\n");
    MacUILib_printf("\n");
    MacUILib_printf("REGULAR FOOD = 1 point\nSUPER FOOD = 10 point\n");
    MacUILib_printf("\n");
    MacUILib_printf("PRESS THE SPACE BAR TO EXIT THE GAME\n");

    
    if(myGM->getLoseFlagStatus() == true){ // checking if the player lost, then exiting the game
        MacUILib_printf("\nYou lost :(\n"); 
        myGM->setExitTrue();
    }
    else if (myGM->getExitFlagStatus() == true){ // checking if the space bar was pressed AKA if the player voluntarily exited the game
        MacUILib_printf("\nYou exited the game.\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void) 
{  
    delete myPlayer;
    delete myGM;
    delete myFood;

    MacUILib_uninit();
}
