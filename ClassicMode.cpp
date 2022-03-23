#include "ClassicMode.h"
#include "Grid.h"
#include "Gamemode.h"

ClassicMode::ClassicMode(){
    neighbors = 0;
}

ClassicMode::~ClassicMode(){

}

char** ClassicMode::PlayClassicMode(char** grid, int row, int col){
    char** shadowGrid = ScanNeighbors(grid, row, col);
    return shadowGrid;
}

char** ClassicMode::ScanNeighbors(char** grid, int row, int col){
    //cout<<"inside scan neighbors"<<endl;
    Gamemode g('X'); //set current to X
    char** shadowGrid = new char* [row];
    for(int i = 0; i < row; ++i) {
      shadowGrid[i] = new char[col];
    }
    for(int x = 0; x < row; ++x){
        for(int y = 0; y < col; ++y){
            shadowGrid[x][y] = grid[x][y];
        }
    }
    //create shadow grid to store current grid
    bool isNeighbor = false; //check if there are neighbors
    int neighbors = 0;

    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){
            //cout<<"line 26"<<endl;
            //cout<<i<<j<<endl;

            if((i != 0 && j != 0) && grid[i-1][j-1] == 'X'){
              //top left
              //cout<<"scan neightbors detecteed top left"<<endl;
              neighbors++;
            }

            if((j != (col-1) && i !=0) && grid[i-1][j+1] == 'X'){
              //top right
              //cout<<"scan neightbors detecteed top right"<<endl;
              neighbors++;
            }

            if((j != (col-1) && i != (row-1)) && grid[i+1][j+1] == 'X'){
              //bottom right
              //cout<<"scan neightbors detecteed bottom right"<<endl;
              neighbors++;
            }

            if((i != (row-1) && j!=0)&& grid[i+1][j-1] == 'X'){
              //bottom left
              //cout<<"scan neightbors detecteed bottom left"<<endl;
              neighbors++;
            }

            if(j!=0 && grid[i][j-1] == 'X'){
              //left
              //cout<<"scan neightbors detecteed left"<<endl;
              neighbors++;
            }

            if(j != (col-1) && grid[i][j+1] == 'X'){
              //right
              //cout<<"scan neightbors detecteed right"<<endl;
              neighbors++;
            }

            if(i != 0 && grid[i-1][j] == 'X'){
              //top
              //cout<<"scan neightbors detecteed top"<<endl;
              neighbors++;
            }

            if(i != (col-1)&& grid[i+1][j] == 'X'){
              //bottom
              //cout<<"scan neightbors detecteed bottom"<<endl;
              neighbors++;
            }
            //cout<<"line 79"<<endl;
            //cout<<neighbors<<endl;
            g.SetCurrent(grid[i][j]);
            shadowGrid[i][j] = g.CheckNextGeneration(neighbors);
            neighbors = 0;
            //cout<<"line 79"<<endl;
      }
    }

    return shadowGrid;
}
