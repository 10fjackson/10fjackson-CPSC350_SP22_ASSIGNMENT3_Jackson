#include "MirrorMode.h"
#include "Grid.h"

MirrorMode::MirrorMode(){

}

MirrorMode::~MirrorMode(){

}

char** MirrorMode::PlayMirrorMode(char** grid){
    char** shadowGrid = ScanNeighbors(grid);
    return shadowGrid;
}

char** MirrorMode::ScanNeighbors(char** grid){
    //Gamemode *g = new Gamemode();
    // char grid[4][4] = { {'X','X','-','-'},
    //                     {'X','X','-','-'},
    //                     {'-','-','-','-'},
    //                     {'-','-','-','-'}};
    Grid g;
    int row = g.getRow(); //set row
    int col = g.getCol(); //set column
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
