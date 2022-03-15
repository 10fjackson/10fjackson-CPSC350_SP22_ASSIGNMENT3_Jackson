#include "ClassicMode.h"

ClassicMode::ClassicMode(){
    int neighbors = 0;
}

ClassicMode::~ClassicMode(){

}

int ClassicMode::ScanNeighbors(){
    string[][] grid = { {'-','-','-','-'},
                        {'-','X','X','-'},
                        {'-','-','X','-'},
                        {'-','-','-','-'}};
    int row = 4;
    int col = 4;
    bool isNeighbor = false;

    for(int i = 0; i < row; i++){ //iterate through rows
        for(int j = 0; j < col; j++){ //iterate through columns

            if(grid[i][j] == 'X'){ //if the cell is not empty

                for(int x = i - 1; x <= i +1; x++){ //check row above and below
                    for(int y = j + 1; y <= j + 1; y++){ //check column above and below

                        if((x == i) && (y == j)){ //ignore cell we're checking

                            if((x < 0) || (y < 0) || (x >= row) || (y >= col)){ //checking within the grid

                                if(grid[x][y] == 'X'){
                                    isNeighbor = true;
                                }
                            }
                        }
                        if(isNeighbor){ //check if it is a neighbor
                            neighbors++; //increment neighbors
                            isNeighbor = false;
                        }
                    }
                }
            }

            grid[i][j] -> CheckNextGeneration(neighbors);
        }
    }
    return neighbors;
}
