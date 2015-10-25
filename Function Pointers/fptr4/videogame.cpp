#include "videogame.h"

videoGame::videoGame()
{

    for(int i = 0; i < 128; ++i)
        whatToDo[i] = &videoGame::nothing;
    whatToDo['u'] = whatToDo['U'] = &videoGame::up;
    whatToDo['d'] = whatToDo['D'] = &videoGame::down;
    whatToDo['l'] = whatToDo['L'] = &videoGame::left;
    whatToDo['r'] = whatToDo['R'] = &videoGame::right;
    whatToDo['q'] = whatToDo['Q'] = &videoGame::bye;
}

videoGame::~videoGame()
{

}

void videoGame::perform()
{
    while(1)
        (this->*whatToDo[rand()%128])();
}

void videoGame::nothing()
{
}

void videoGame::up()
{
    cout<<"UP!"<<endl;
}

void videoGame::down()
{
    cout<<"DOWN!"<<endl;
}

void videoGame::left()
{
    cout<<"LEFT!"<<endl;
}

void videoGame::right()
{
    cout<<"RIGHT!"<<endl;
}


void videoGame::bye()
{
    cout<<"BYE!"<<endl;
    exit(0);
}
