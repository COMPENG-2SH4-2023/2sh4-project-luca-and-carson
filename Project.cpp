#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
Food* foodPos;
objPos playerPos;



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

    myGM = new GameMechs(30, 15); //makes board size 30 and 15
    myPlayer = new Player(myGM);  
    foodPos = new Food();
    

    //think about when to generate the new food
    //think about whether you want to set up a debug key to call the food generatuon routine for verify.
    //foodPos->generateFood(playerPos);
    //generate food requires player ref. provide after player object is instantiated
}

void GetInput(void)
{
    if (MacUILib_hasChar()){
        myGM->setInput(MacUILib_getChar());
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
    

    myPlayer->getPlayerPos(playerPos);

    for(int y = 0;y <= myGM->getBoardSizeY() - 1;y++)
    {
        for(int x = 0;x <= myGM->getBoardSizeX() - 1;x++)
        {
            if(y == 0 || y == myGM->getBoardSizeY() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if(x == 0 || x == myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if(x == playerPos.x && y == playerPos.y)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            // else if (x == foodPos->x && y == foodPos->y){
            //     MacUILib_printf("f");
            // }

            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c",'\n');
    }    
    
    MacUILib_printf("Score: %d, Boardsize: %dx%d, Playerpos: <%d %d> + %c\n", myGM->getScore(), myGM->getBoardSizeX(), myGM->getBoardSizeY(), playerPos.x, playerPos.y, playerPos.symbol);
    //MacUILib_printf("food x: %d, food y: %d", foodPos->x, foodPos->y);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    
    delete myGM;
    delete myPlayer;
    delete foodPos;
    MacUILib_uninit();
}
