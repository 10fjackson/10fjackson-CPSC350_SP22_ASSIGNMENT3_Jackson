<<<<<<< HEAD

#include "GameOfLife.h"
=======
#include "Gamemode.h"
#include "ClassicMode.h"
>>>>>>> 8851785f57cfd317b26a5af8e3588ce9e66a75a7

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

void Gamemode::PlayGame(){
    ClassicMode *c = new ClassicMode();
    int gamemode;
    // DoughnutMode *d = new DoughnutMode();
    // MirrorMode *m = new MirrorMode();

    if(gamemode == 0){ //play classic mode
        c -> PlayClassicMode();
    } else if (gamemode == 1){ //play doughnut mode
        // d -> PlayDoughnutMode();
    } else if (gamemode == 2){ //play mirror mode
        // m -> PlayMirrorMode();
    }
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

void Gamemode::SetCurrent(char c){
    if(c == 'X'){
        current = true;
    } else {
        current = false;
    }
    // cout << current << endl;
}
