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

void Gamemode::PlayGame(){
    ClassicMode *c = new ClassicMode();
    int gamemode;
    DoughnutMode *d = new DoughnutMode();
    MirrorMode *m = new MirrorMode();

    if(gamemode == 0){ //play classic mode
        c -> PlayClassicMode();
    } else if (gamemode == 1){ //play doughnut mode
        d -> PlayDoughnutMode();
    } else if (gamemode == 2){ //play mirror mode
        m -> PlayMirrorMode();
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
