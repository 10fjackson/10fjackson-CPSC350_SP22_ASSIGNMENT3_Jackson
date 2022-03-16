#include "Gamemode.h"

Gamemode::Gamemode(){
    gamemodeType = 0;
    next = false;
    current = false;
}

Gamemode::Gamemode(bool current){
    current = current;
}

Gamemode::~Gamemode(){

}

void Gamemode::SetGamemode(int gamemode){
    int gamemodeType = gamemode;
    // cout << gamemodeType << endl;
}

void Gamemode::CheckNextGeneration(int neighbors){
    if(neighbors <= 1){
        next = false;
    } else if (neighbors == 2){
        next = current;
    } else if (neighbors == 3){
        next = true;
    } else {
        next = false;
    }
}
