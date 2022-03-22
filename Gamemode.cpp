#include "Gamemode.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

Gamemode::Gamemode(){
    gamemodeType = 0;
    next = ' ';
    current = ' ';
}

Gamemode::Gamemode(char current){
    current = current;
}

Gamemode::~Gamemode(){

}

void Gamemode::SetGamemode(int gamemode){
    int gamemodeType = gamemode;
    // cout << gamemodeType << endl;
}

char** Gamemode::PlayGame(char** grid){
    ClassicMode *c = new ClassicMode();
    int gamemode;
    char** shadowGrid;
    DoughnutMode *d = new DoughnutMode();
    MirrorMode *m = new MirrorMode();

    if(gamemode == 0){ //play classic mode
        shadowGrid = c -> PlayClassicMode(grid);
        return shadowGrid;
    } else if (gamemode == 1){ //play doughnut mode
        shadowGrid = d -> PlayDoughnutMode(grid);
        return shadowGrid;
    } else if (gamemode == 2){ //play mirror mode
        shadowGrid = m -> PlayMirrorMode(grid);
        return shadowGrid;
    }
}

char Gamemode::CheckNextGeneration(int neighbors){
    if(neighbors <= 1){
        return '-';
    } else if (neighbors == 2){
        return current;
    } else if (neighbors == 3){
        return 'X';
    } else {
        return '-';
    }
}

void Gamemode::SetCurrent(char c){
    if(c == 'X'){
        current = c;
    } else {
        current = '-';
    }
    // cout << current << endl;
}
