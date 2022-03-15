#include "ClassicMode.h"

ClassicMode::ClassicMode(){
    int neighbors = 0;
}

ClassicMode::~ClassicMode(){

}

int ClassicMode::ScanNeighbors(Grid grid){
    for(int i = 0; i < row; i++){ //iterate through rows
        for(int j = 0; j < col; j++){ //iterate through columns

            if(grid[i][j] == 'X'){ //if the cell is not empty

                for(int x = i - 1; x <= i +1; x++){ //check row above and below
                    for(int y = j + 1; y <= j + 1; y++){ //check column above and below

                        if((x == i) && (y == j)){ //ignore cell we're checking

                            if((x < 0) || (y < 0) || (x >= row) || (y >= col)){ //checking within the grid

                                if(CheckCell(grid, x, y)){
                                    neighbors++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return neighbors;
}

bool ClassicMode::CheckCell(Grid grid, int x, int y){
    if(grid[x][y] == 'X'){
        return true;
    } else {
        return false;
    }
}
