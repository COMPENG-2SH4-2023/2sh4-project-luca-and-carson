#include "MacUILib.h"
#include "objPos.h"
#include "Food.h"
#include <cstdlib>
#include <time.h>

objPos* randomPos = new objPos();

Food::Food(){
    foodPos.setObjPos(-1, -1, 'f'); //initialize food position outside of game board
}

Food::~Food(){
    delete randomPos;
}
void Food::generateFood(objPos blockOff){
    //generate random x and y coords and make sure they are not border or blockoff pos. 
    int i = 1;
    while(i){
        randomPos->x = rand() % (mechInfo.getBoardSizeX() - 2) + 1;
        randomPos->y = rand() % (mechInfo.getBoardSizeY() - 2) + 1;

        if(blockOff.isPosEqual(randomPos))
        {
            i = 1;
        }
        else{
            foodPos.setObjPos(randomPos->x, randomPos->y, 'f');
            i = 0;
        }
    }
    //remember isPosequal() method.
}
             
void Food::getfoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);;
}