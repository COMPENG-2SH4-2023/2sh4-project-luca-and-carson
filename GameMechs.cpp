  #include "GameMechs.h"
  #include "MacUILib.h"


 //think aboutn where to seed the rmg

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1, -1, 'f'); //initialize food position outside of game board
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;

    foodPos.setObjPos(-1, -1, 'f');
}

// do you need a destructor?


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
    MacUILib_printf("You Lose");
}

void GameMechs::setLoseFlag(){
    loseFlag = true;
    MacUILib_printf("Simply you Lose");
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore(){
    return score;

}

void GameMechs::incrementScore(){
    score ++;
}

void GameMechs::generateFood(objPos blockOff){
    //generate random x and y coords and make sure they are not border or blockoff pos.
    int rand_x, rand_y;
    rand_x = rand() % (getBoardSizeX() - 2) + 1;
    rand_y = rand() % (getBoardSizeY() - 2) + 1;
    //check x and y against 0 and boardsizeX / Y.
    if(rand_x == 0 || rand_y == 0 ){

    }
    else if (rand_x == getBoardSizeX() - 1 || rand_y == getBoardSizeY() - 1){

    }
    //else if (blockOff->isPosEqual())
    //remember isPosequal() method.
}
             
void getfoodPos(objPos &returnPos){

}