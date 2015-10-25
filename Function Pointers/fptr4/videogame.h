#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

class videoGame;

typedef void (videoGame::*fptr)();

class videoGame
{
    public:
        videoGame();
        ~videoGame();
        void perform();

    private:
        fptr whatToDo[128];

        void up();
        void down();
        void left();
        void right();
        void nothing();
        void bye();
};

#endif // VIDEOGAME_H
