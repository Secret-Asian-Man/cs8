#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

typedef void (*fptr)();

void initialize( fptr f[]);
void nothing();
void up();
void down();
void left();
void right();
void bye();
using namespace std;

int main()
{
    fptr whatToDo[128];
    srand(time(0));
    initialize(whatToDo);
    while(1)
        (whatToDo[rand()%128])();
    return 0;
}


void initialize( fptr f[])
{
    for(int i = 0; i < 128; ++i)
        f[i] = nothing;
    f['u'] = f['U'] = up;
    f['d'] = f['D'] = down;
    f['l'] = f['L'] = left;
    f['r'] = f['R'] = right;
    f['q'] = f['Q'] = bye;
}

void nothing()
{
}

void up()
{
    cout<<"UP!"<<endl;
}

void down()
{
    cout<<"DOWN!"<<endl;
}

void left()
{
    cout<<"LEFT!"<<endl;
}

void right()
{
    cout<<"RIGHT!"<<endl;
}


void bye()
{
    cout<<"BYE!"<<endl;
    exit(0);
}
