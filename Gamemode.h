#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <iostream>
using namespace std;


class Gamemode{
    public:
        Gamemode();
        Gamemode(bool current);
        ~Gamemode();

        void PlayGame();
        void SetGamemode(int gamemode);
        void CheckNextGeneration(int neighbors);
        void SetCurrent(char current);

        int gamemodeType;


    private:
        bool current; //current cell status (true if occupied & false if empty)
        bool next; //cell status for next generation


};

#endif
