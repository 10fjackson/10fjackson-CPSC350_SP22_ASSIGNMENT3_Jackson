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
    ClassicMode *c = new ClassicMode(); //create a pointer to classic mode
    int gamemode;
    char** shadowGrid;
    DoughnutMode *d = new DoughnutMode(); //create a pointer to doughnut mode
    MirrorMode *m = new MirrorMode(); //create a pointer to mirror mode

    if(gamemode == 0){ //play classic mode
        shadowGrid = c -> PlayClassicMode(grid); //play clqssic mode and store next generation grid in shadow grid
        return shadowGrid;
    } else if (gamemode == 1){ //play doughnut mode
        shadowGrid = d -> PlayDoughnutMode(grid); //play doughnut mode and store next generation grid in shadow grid
        return shadowGrid;
    } else if (gamemode == 2){ //play mirror mode
        shadowGrid = m -> PlayMirrorMode(grid); //play mirror mode and store next generation grid in shadow grid
        return shadowGrid;
    }
}

char Gamemode::CheckNextGeneration(int neighbors){
    if(neighbors <= 1){ //if there is less than 1 neighbor then the cell will not be occupied
        return '-';
    } else if (neighbors == 2){ //if there are 2 neighbors then cell remains stable
        return current;
    } else if (neighbors == 3){ //if there are are 3 neighbors then cell is occupied
        return 'X';
    } else { //more than 3 means the cell will be empty
        return '-';
    }
}

void Gamemode::SetCurrent(char c){
    if(c == 'X'){ //set current to cell char
        current = c;
    } else {
        current = '-';
    }
    // cout << current << endl;
}
