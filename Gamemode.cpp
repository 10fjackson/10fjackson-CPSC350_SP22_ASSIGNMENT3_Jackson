include "Gamemode.h"

Gamemode::Gamemode(){

}

Gamemode::Gamemode(bool current){
    current = current;
}

Gamemode::~Gamemode(){

}

void Gamemode::SelectGamemode(char gamemode){
    if (gamemode == 'd'){

    } else if (gamemode == 'm'){

    } else if (gamemode == 'c'){

    } else {
        cout << "Incorrect gamemode type" << endl;
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
