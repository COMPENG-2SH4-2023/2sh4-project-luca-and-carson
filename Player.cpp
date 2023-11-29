#include "Player.h"

#define SIZEx 20
#define SIZEy 10


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(SIZEx/2,SIZEy/2,'*');
    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
}


Player::~Player()
{
    delete mainGameMechsRef;
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    switch(mainGameMechsRef->getInput())
    {
            case 'w':
                if(myDir != DOWN){
                    myDir = UP;
                }
                break;

            case 's':
                if(myDir != UP){
                    myDir = DOWN;
                }
                break;

            case 'a':
                if(myDir != RIGHT){
                    myDir = LEFT;
                }
                break;

            case 'd':
                if(myDir != LEFT){
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
    switch(mainGameMechsRef->getInput()){
        case UP:
            if(playerPos.y == SIZEy - 9){
                playerPos.y = SIZEy - 1;
                break;
            }
            playerPos.y--;
            break;

        case DOWN:
            if(playerPos.y == SIZEy - 1){
                playerPos.y = SIZEy - 9;
                break;
            }
            playerPos.y++;
            break;

        case RIGHT:
            if(playerPos.x == SIZEx - 1){
                playerPos.x = SIZEx - 19;
                break;
            }
            playerPos.x++;
            break;

        case LEFT:
            if(playerPos.x == SIZEx - 19){
                playerPos.x = SIZEx - 1;
                break;
            }
            playerPos.x--;
            break;
    }
    // PPA3 Finite State Machine logic
}
