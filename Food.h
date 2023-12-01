
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

#ifndef FOOD_H
#define FOOD_H

class Food
{
    private:
        objPos foodPos;
        GameMechs* mechInfo;
        objPosArrayList* playerBody;
    public:

        Food(GameMechs* gameMechs);
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        void getfoodPos(objPos &returnPos);
};


#endif