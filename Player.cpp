#include "Player.h"
#include "GameMechs.h"
#include "Food.h"



Player::Player(GameMechs* thisGMRef, Food* food)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');
    // more actions to be included
    foodInfo = food;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
}


Player::~Player()
{
    delete mainGameMechsRef;
    delete playerPosList;
    delete foodInfo;
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    //returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    
    switch(mainGameMechsRef->getInput())
    {
            case 'w':
                if(myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case 's':
                if(myDir != UP)
                {
                    myDir = DOWN;
                }
                break;

            case 'a':
                if(myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case 'd':
                if(myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    //objPos newHead;
    objPos currentHead; // holding position info of the current head
    playerPosList->getHeadElement(currentHead);

    switch(myDir){
        case UP:
            if(currentHead.y == 1)
            {
                currentHead.y = mainGameMechsRef->getBoardSizeY() - 2;
                break;
            }
            currentHead.y--;
            break;

        case DOWN:
            if(currentHead.y == mainGameMechsRef->getBoardSizeY() - 2)
            {
                currentHead.y = 1;
                break;
            }
            currentHead.y++;
            break;

        case RIGHT:
            if(currentHead.x == mainGameMechsRef->getBoardSizeX() - 2)
            {
                currentHead.x = 1;
                break;
            }
            currentHead.x++;
            break;

        case LEFT:
            if(currentHead.x == 1)
            {
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
                break;
            }
            currentHead.x--;
            break;
        case STOP:
        default:
            break;
    }
    // PPA3 Finite State Machine logic
    //new current head should be inserted into the head of the list
    if(checkFoodConsumption())
    {
        playerPosList->insertHead(currentHead);
    }
    else
    {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }
    
    //then remove tail
    
}

bool Player::checkFoodConsumption(){
    objPos tempFoodPos;
    foodInfo->getfoodPos(tempFoodPos);

    objPos tempHeadPos;
    playerPosList->getHeadElement(tempHeadPos);
    if(tempHeadPos.x == tempFoodPos.x && tempHeadPos.y == tempFoodPos.y){
        return true;
    }
    else{
        return false;
    }
        
}        
// void Player::increasePlayerLength(){
//     objPos tempTailPos;
//     playerPosList->getTailElement(tempTailPos);
//     playerPosList->insertTail(tempTailPos);
// }
        