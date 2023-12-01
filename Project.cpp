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
objPosArrayList* playerBody;




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
    playerBody = new objPosArrayList();
    foodPos = new Food(myGM);
    myPlayer = new Player(myGM, foodPos);  
    
    playerBody = myPlayer->getPlayerPos();
    foodPos->generateFood(playerBody);
    //think about when to generate the new food
    //think about whether you want to set up a debug key to call the food generatuon routine for verify.
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
    if(myPlayer->checkSelfCollision())
    {
        myGM->setLoseFlag();
    }else
    {
        myPlayer->movePlayer();
        myGM->clearInput();
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    // objPos tempPos;
    // myPlayer->getPlayerPos(tempPos);
    bool drawn;

    
    objPos tempBody;

    objPos tempF;
    foodPos->getfoodPos(tempF);

    for(int y = 0; y <= myGM->getBoardSizeY() - 1; y++)
    {
        for(int x = 0; x <= myGM->getBoardSizeX() - 1; x++)
        {
            drawn = false;
            for(int k = 0; k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(tempBody.x == x && tempBody.y == y){
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue;
            //if player body was drawn do not draw anything below

            if(y == 0 || y == myGM->getBoardSizeY() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if(x == 0 || x == myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            // else if(x == tempPos.x && y == tempPos.y)
            // {
            //     MacUILib_printf("%c", tempPos.symbol);
            // }
            else if (x == tempF.x && y == tempF.y){
                MacUILib_printf("%c", tempF.symbol);
            }

            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c",'\n');
    }    
    
    MacUILib_printf("Score: %d\n", myGM->getScore()); 
    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("You ate yourself: GAME OVER");
    }
    else if(myGM->getExitFlagStatus()){
        MacUILib_printf("You have exited the game");
    }
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
