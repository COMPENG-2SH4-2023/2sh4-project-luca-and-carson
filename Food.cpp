#include "MacUILib.h"
#include "objPos.h"
#include "Food.h"
#include <cstdlib>
#include <time.h>



Food::Food(GameMechs* gameMechs){
    foodPos.setObjPos(-1, -1, 'o'); //initialize food position outside of game board
    mechInfo = gameMechs;
}

Food::~Food(){
    
}
void Food::generateFood(objPos blockOff){
    //generate random x and y coords and make sure they are not border or blockoff pos.
    int invalidXY = 1;
    objPos randomPos;
    randomPos = objPos();
    while(invalidXY == 1){
        randomPos.x = rand() % (mechInfo->getBoardSizeX() - 2) + 1;
        randomPos.y = rand() % (mechInfo->getBoardSizeY() - 2) + 1;

        if(blockOff.isPosEqual(&randomPos)){
            invalidXY = 1;
        }
        else{
            foodPos.x = randomPos.x;
            foodPos.y = randomPos.y;
            invalidXY = 0;
        }
    }
    //remember isPosequal() method.
}
             
void Food::getfoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);;
}