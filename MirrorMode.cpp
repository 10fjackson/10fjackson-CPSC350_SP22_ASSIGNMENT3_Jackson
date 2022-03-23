#include "MirrorMode.h"
#include "Grid.h"
#include "Gamemode.h"

MirrorMode::MirrorMode(){

}

MirrorMode::~MirrorMode(){

}

char** MirrorMode::PlayMirrorMode(char** grid, int row, int col){
    char** shadowGrid = ScanNeighbors(grid, row, col);
    return shadowGrid;
}

char** MirrorMode::ScanNeighbors(char** grid, int row, int col){
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
    bool isNeighbor = false;
    int neighbors = 0;

    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){

          //corners
          // will add only number of mirrored neighbors
          if(i == 0 && j == 0){
            //top left corner
            neighbors += 3;
            if(grid[i+1][j] == 'X'){
              neighbors++;
            }
            if(grid[i][j+1] == 'X'){
              neighbors++;
            }
          }

          if(i == 0 && j == (col-1)){
            //top right corner
            neighbors += 3;
            if(grid[i+1][j] == 'X'){
              neighbors++;
            }
            if(grid[i][j-1] == 'X'){
              neighbors++;
            }
          }

          if(i == (row-1) && j == 0){
            //bottom left corner
            neighbors += 3;
            if(grid[i-1][j] == 'X'){
              neighbors++;
            }
            if(grid[i][j+1] == 'X'){
              neighbors++;
            }
          }

          if(i == (row-1) && j == (col-1)){
            //bottom right corner
            neighbors += 3;
            if(grid[i-1][j] == 'X'){
              neighbors++;
            }
            if(grid[i][j-1] == 'X'){
              neighbors++;
            }
          }

          //Neighbors off each wall

          //top wall
          if(i == 0 && j != 0 && j != (col-1)){
            neighbors++; // adds mirror of itself
            if(grid[i][j-1] == 'X'){
              neighbors++;
            }
            if(grid[i][j+1] == 'X'){
              neighbors++;
            }
          }
          //left wall
          if(j == 0 && i != (row-1) && i != 0){
            neighbors++; // adds mirror of itself
            if(grid[i-1][j] == 'X'){
              neighbors++;
            }
            if(grid[i+1][j] == 'X'){
              neighbors++;
            }
          }
          //right wall
          if(j == (col-1) && i != 0 && i != (row-1)){
            neighbors++; // adds mirror of itself
            if(grid[i+1][j] == 'X'){
              neighbors++;
            }
            if(grid[i-1][j] == 'X'){
              neighbors++;
            }
          }

          //bottom wall
          if(i == (row-1) && j != 0 && j != (col-1)){
            neighbors++; // adds mirror of itself
            if(grid[i][j-1] == 'X'){
              neighbors++;
            }
            if(grid[i][j+1] == 'X'){
              neighbors++;
            }
          }


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
          g.SetCurrent(grid[i][j]);
          shadowGrid[i][j] = g.CheckNextGeneration(neighbors);
          neighbors = 0;

      }
    }
    return shadowGrid;


}
