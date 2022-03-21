#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <iostream>
using namespace std;


class Gamemode{
    public:
        Gamemode();
        Gamemode(char current);
        ~Gamemode();

        void PlayGame();
        void SetGamemode(int gamemode);
        char CheckNextGeneration(int neighbors);
        void SetCurrent(char current);

        int gamemodeType;


    private:
        char current; //current cell status
        char next; //cell status for next generation


};

#endif
