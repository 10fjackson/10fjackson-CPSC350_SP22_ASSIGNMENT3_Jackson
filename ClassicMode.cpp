#include "ClassicMode.h"
#include "Gamemode.h"

ClassicMode::ClassicMode(){
    neighbors = 0;
}

ClassicMode::~ClassicMode(){

}

void ClassicMode::PlayClassicMode(){
    ScanNeighbors();
}

void ClassicMode::ScanNeighbors(){
    Gamemode *g = new Gamemode();
    char grid[4][4] = { {'-','-','-','-'},
                        {'-','-','-','-'},
                        {'-','-','X','-'},
                        {'-','-','-','-'}};
    int row = 4;
    int col = 4;
    bool isNeighbor = false;
    int neighbors = 0;

    for(int i = row - 1; i <= row + 1; ++i){
        for(int j = col - 1; j <= col + 1; ++j){
            g -> SetCurrent(grid[i][j]);
            // cout << grid[i][j] << endl;
        }
    }
    // return neighbors;
}
