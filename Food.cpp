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
void Food::generateFood(objPosArrayList* blockOff){
    //generate random x and y coords and make sure they are not border or blockoff pos.
    int invalidXY = 1;
    objPos randomPos;
    objPos tempBody;
    playerBody = blockOff;

    randomPos = objPos();
    while(invalidXY == 1){
        randomPos.x = rand() % (mechInfo->getBoardSizeX() - 2) + 1;
        randomPos.y = rand() % (mechInfo->getBoardSizeY() - 2) + 1;
        for(int i = 0; i < blockOff->getSize(); i++){ //to check each element of the current snake
            playerBody->getElement(tempBody, i); //go to the element
            //if(blockOff.isPosEqual(&tempBody)){
            if (randomPos.x == tempBody.x && randomPos.y == tempBody.y){ //check if the elements position is equal to the random position
                invalidXY = 1;//it is invalid if the desired food position is a current snake position
            }
            else{
                foodPos.x = randomPos.x;
                foodPos.y = randomPos.y;
                invalidXY = 0;
            }
        }
            
    }
    //remember isPosequal() method.
}
             
void Food::getfoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);;
}