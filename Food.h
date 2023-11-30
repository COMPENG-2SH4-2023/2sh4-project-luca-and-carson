
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

#ifndef FOOD_H
#define FOOD_H

class Food
{
    private:
        objPos foodPos;
        GameMechs mechInfo;
    public:

        Food();
        ~Food();

        void generateFood(objPos blockOff);
        void getfoodPos(objPos &returnPos);
};


#endif