#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

#define SIZEx 20
#define SIZEy 10

Player* HeadPos;


int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    
    
    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    for(int y = 0;y <= SIZEy - 1;y++)
    {
        for(int x = 0;x <= SIZEx - 1;x++)
        {
            if(y == 0 || y == SIZEy - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if(x == 0 || x == SIZEx - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if(x == HeadPos.x && y == HeadPos.y)
            {
                MacUILib_printf("%c",HeadPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c",'\n');
    }    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
