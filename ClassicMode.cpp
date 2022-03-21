#include "ClassicMode.h"
#include "Grid.h"
#include "Gamemode.h"

ClassicMode::ClassicMode(){
    neighbors = 0;
}

ClassicMode::~ClassicMode(){

}

void ClassicMode::PlayClassicMode(){
    Grid g;
    char** grid = g.getGrid();
    ScanNeighbors(grid);
}

void ClassicMode::ScanNeighbors(char** grid){
    Grid g;
    // char grid[4][4] = { {'-','X','-','-'},
    //                     {'X','X','X','-'},
    //                     {'-','-','-','-'},
    //                     {'-','-','-','-'}};
    int row = g.getRow();
    int col = g.getCol();
    char** shadowGrid = g.shadowGrid;
    bool isNeighbor = false;
    int neighbors = 0;

    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){
        if(grid[i][j] == 'X'){
            Gamemode *g = new Gamemode('X');

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
            shadowGrid[i][j] = g->CheckNextGeneration(neighbors);
            neighbors = 0;
        }
      }
    }


}
