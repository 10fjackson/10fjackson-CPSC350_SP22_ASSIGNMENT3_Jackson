#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <iostream>


class Gamemode{
    public:
        Gamemode();
        Gamemode(bool current);
        ~Gamemode();

        void SelectGamemode(char gamemode);
        void CheckNextGeneration(int neighbors);




    private:
        bool current; //current cell status (true if occupied & false if empty)
        bool next; //cell status for next generation


};

#endif
