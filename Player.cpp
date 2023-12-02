#include "Player.h"
#include "GameMechs.h"
#include "Food.h"



Player::Player(GameMechs* thisGMRef, Food* food, objPosArrayList* Bucket)
{
    mainGameMechsRef = thisGMRef;
    foodInfo = food;
    foodBucket = Bucket;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');

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
                
            case ' ':
                mainGameMechsRef->setExitTrue();
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
    if(checkFoodConsumptionNormal()) //if food is consumed 
    {
        playerPosList->insertHead(currentHead); //increase the player 
        foodBucket->resetSize();
        foodInfo->generateFood(playerPosList, foodBucket);
        mainGameMechsRef->incrementScore();
    }
    else if(checkFoodConsumptionSpecial())
    {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
        foodBucket->resetSize();
        foodInfo->generateFood(playerPosList, foodBucket);
        for (int i = 0; i < 5; i ++)
        {
            mainGameMechsRef->incrementScore();
        }
    }
    else
    {
        playerPosList->insertHead(currentHead); //otherwise use regular moving algorithm
        playerPosList->removeTail();
    }
    //then remove tail
    
}

bool Player::checkFoodConsumptionNormal()
{
    objPos tempHeadPos;
    objPos tempFood;
    for(int i = 0; i < foodBucket->getSize(); i++)
    {
        playerPosList->getHeadElement(tempHeadPos);
        foodBucket->getElement(tempFood, i);
        if(tempHeadPos.x == tempFood.x && tempHeadPos.y == tempFood.y)
        {
            if(tempFood.symbol == 'o')
            {
                return true;
            }
        }
    }
    return false;
}
bool Player::checkFoodConsumptionSpecial()
{
    objPos tempHeadPos;
    objPos tempFood;
    for(int i = 0; i < foodBucket->getSize(); i++)
    {
        playerPosList->getHeadElement(tempHeadPos);
        foodBucket->getElement(tempFood, i);
        if(tempHeadPos.x == tempFood.x && tempHeadPos.y == tempFood.y)
        {
            if(tempFood.symbol == 'x')
            {
                return true;
            }
        }
    }
    return false;
}
bool Player::checkSelfCollision(){
    objPos tempHeadPos;
    playerPosList->getHeadElement(tempHeadPos);
    objPos tempPlayerElement;

    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(tempPlayerElement, i);
        if(tempHeadPos.x == tempPlayerElement.x && tempHeadPos.y == tempPlayerElement.y){
            return true;
        }
    }return false;

}
        