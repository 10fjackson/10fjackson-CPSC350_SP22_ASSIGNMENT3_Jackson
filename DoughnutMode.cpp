//#include "Gamemode.h"
#include "DoughnutMode.h"
#include "Grid.h"

DoughnutMode::DoughnutMode(){

}

DoughnutMode::~DoughnutMode(){

}

void DoughnutMode::PlayDoughnutMode(){
    Grid g;
    char** grid = g.getGrid();
    ScanNeighbors(grid);
}

void DoughnutMode::ScanNeighbors(char** grid){
  // char grid[4][4] = { {'X','-','X','X'},
  //                     {'X','-','X','X'},
  //                     {'-','-','-','-'},
  //                     {'X','-','X','X'}};
  Grid g;
  int row = g.getRow();
  int col = g.getCol();
  bool isNeighbor = false;
  int neighbors = 0;

  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      if(grid[i][j] == 'X'){
        if(i == 0 && j == 0){
          //top left corner
          if(grid[row-1][j] == 'X'){
            neighbors++;
          }
          if(grid[i][col-1] == 'X'){
            neighbors++;
          }
          if(grid[row-1][col-1] == 'X'){
            neighbors++;
          }
          if(grid[row-1][j+1] == 'X'){
            neighbors++;
          }
          if(grid[i+1][col-1] == 'X'){
            neighbors++;
          }

        }

        if(i == 0 && j == (col-1)){
          //top right corner
          if(grid[i][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i+1][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[row-1][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[row-1][j] == 'X'){
            neighbors++;
          }
          if(grid[row-1][j-1] == 'X'){
            neighbors++;
          }
        }

        if(i == (row-1) && j == 0){
          //bottom left corner
          if(grid[i-(row-1)][j] == 'X'){
            neighbors++;
          }
          if(grid[i-(row-1)][j+1] == 'X'){
            neighbors++;
          }
          if(grid[i][col-1] == 'X'){
            neighbors++;
          }
          if(grid[i-1][col-1] == 'X'){
            neighbors++;
          }
          if(grid[i-(row-1)][col-1] == 'X'){
            neighbors++;
          }
        }

        if(i == (row-1) && j == (col-1)){
          //bottom right corner
          if(grid[i-(row-1)][j] == 'X'){
            neighbors++;
          }
          if(grid[i-(row-1)][j-1] == 'X'){
            neighbors++;
          }
          if(grid[i-(row-1)][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i-1][j-(col-1)] == 'X'){
            neighbors++;
          }
        }
        //checks all the walls for items opposite side neighboring with them
        //top wall
        if(i == 0 && j != 0 && j != (col-1)){
          if(grid[i+(col-1)][j] == 'X'){
            neighbors++;
          }
          if(grid[i+(col-1)][j+1] == 'X'){
            neighbors++;
          }
          if(grid[i+(col-1)][j-1] == 'X'){
            neighbors++;
          }
        }
        //left wall
        if(j == 0 && i != (row-1) && i != 0){
          if(grid[i][j+(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i+1][j+(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i-1][j+(col-1)] == 'X'){
            neighbors++;
          }
        }
        //right wall
        if(j == (col-1) && i != 0 && i != (row-1)){
          if(grid[i][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i+1][j-(col-1)] == 'X'){
            neighbors++;
          }
          if(grid[i-1][j-(col-1)] == 'X'){
            neighbors++;
          }
        }

        //bottom wall
        if(i == (row-1) && j != 0 && j != (col-1)){
          if(grid[i-(col-1)][j] == 'X'){
            neighbors++;
          }
          if(grid[i-(col-1)][j+1] == 'X'){
            neighbors++;
          }
          if(grid[i-(col-1)][j-1] == 'X'){
            neighbors++;
          }
        }

        //normal grid checking
        if(grid[i-1][j-1] == 'X' && (i != 0 && j != 0)){
          //top left
          cout<<"scan neightbors detecteed top left"<<endl;
          neighbors++;
        }

        if(grid[i-1][j+1] == 'X' && (j != (col-1) && i !=0)){
          //top right
          cout<<"scan neightbors detecteed top right"<<endl;
          neighbors++;
        }

        if(grid[i+1][j+1] == 'X' && (j != (col-1) && i != (row-1))){
          //bottom right
          cout<<"scan neightbors detecteed bottom right"<<endl;
          neighbors++;
        }

        if(grid[i+1][j-1] == 'X' && (i != (row-1) && j!=0)){
          //bottom left
          cout<<"scan neightbors detecteed bottom left"<<endl;
          neighbors++;
        }

        if(grid[i][j-1] == 'X' && j!=0){
          //left
          cout<<"scan neightbors detecteed left"<<endl;
          neighbors++;
        }

        if(grid[i][j+1] == 'X' && j != (col-1)){
          //right
          cout<<"scan neightbors detecteed right"<<endl;
          neighbors++;
        }

        if(grid[i-1][j] == 'X' && i != 0){
          //top
          cout<<"scan neightbors detecteed top"<<endl;
          neighbors++;
        }

        if(grid[i+1][j] == 'X' && i != (col-1)){
          //bottom
          cout<<"scan neightbors detecteed bottom"<<endl;
          neighbors++;
        }
        cout<<neighbors<<endl;
        neighbors = 0;

      }
    }
  }
}
