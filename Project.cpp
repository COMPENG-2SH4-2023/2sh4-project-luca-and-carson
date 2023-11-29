#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;



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

    myGM = new GameMechs(26, 13); //makes board size 26 and 13
    myPlayer = new Player(myGM);  
    
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
    objPos playerPos;

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
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c",'\n');
    }    
    
    MacUILib_printf("Boardsize: %dx%d, Playerpos: <%d %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), playerPos.x, playerPos.y, playerPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    
    delete(myGM);
    delete(myPlayer);

    MacUILib_uninit();
}
