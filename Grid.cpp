#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
  row = 0;
  col = 0;
  density = 0.0;
  grid = new char*[0];
}
Grid::Grid(int r, int c){
  //number of rows in the grid
  row = r;
  //number of columns in the grid
  col = c;
  //creates a new row for the grid
  grid = new char*[row];
  //loops through the rows and creates a column in each row
  for(int i = 0; i < row; ++i) {
    grid[i] = new char[col];
  }
}

Grid::~Grid(){
  //garbage collects the grid
  cout<<"Deleting Grid"<<endl;
  for(int i = 0; i < row; ++i) {
    delete [] grid[i];
  }
  delete [] grid;
}
void Grid::Test(){
  //double for loop to fill the grid with chars
  for(int i = 0; i < row;++i){
    for(int j = 0; j < col; ++j){
      //prints out the char in that spot
      cout<<grid[i][j];
    }
    cout<<endl;
  }
}
char** Grid::createGrid(string layout, int r, int c, float d){
  int row = r;
  // cout << "Row :" << row << endl;
  int col = c;
  // cout << "Col :" << col << endl;
  float density = 1/d;
  // cout << "Density :" << density << endl;
      // char** grid;
  grid = new char* [row];
  for(int i = 0; i < row; ++i) {
      grid[i] = new char[col];
  }
  // cout << "Row :" << row << endl;
  // cout << "Col :" << col << endl;
  int actualx;
  int numx = ((row*col)/density);
  if(layout == "random"){
    //num will be a 1 or 2, will decide whether there is an X in this space
    for(int i = 0; i < row;++i){
      for(int j = 0; j < col; ++j){
        int num = rand() % 2;
        if(num == 1){
          // cout<<"58"<<endl;
          grid[i][j] = 'X';
          // cout<<"60"<<endl;
          actualx++;

        }
        else{
          grid[i][j] = '-';
        }
        num = 0;
      }
    }
    // cout<<"62"<<endl;

    if(actualx<numx){
      // while(actualx != numx){
          int r = rand() % (row-1);
          int c = rand() % (col-1);
          if(grid[r][c] == 'X'){
            grid[r][c] = '-';
            actualx++;
          }
        // }
    }

    if(actualx>numx){
      // while(actualx != numx){
          int r = rand() % (row-1);
          int c = rand() % (col-1);
          if(grid[r][c] == '-'){
            grid[r][c] = 'X';
            actualx--;
          }
        // }
    }
  }//end of random if statement
  for(int i = 0; i < row; ++i){
      for(int j = 0; i < col; ++j){
          cout << grid[i][j];
      }
      cout << endl;
  }
  return grid;

}

char** Grid::createShadowGrid(char** grid){
    int row;
    int col;
    shadowGrid = new char* [row];
    for(int i = 0; i < row; ++i) {
      shadowGrid[i] = new char[col];
    }
    for(int x = 0; x < row; ++x){
        for(int y = 0; y < col; ++y){
            shadowGrid[x][y] = grid[x][y];
        }
    }
}


//Accessors
char** Grid::getGrid(){
    return grid;
}

int Grid::getRow(){
    return row;
}

int Grid::getCol(){
    return col;
}

//Modifiers
void Grid::setGrid(char** g){
    grid = g;
}

void Grid::setRow(int r){
    row = r;
}

void Grid::setCol(int c){
    col = c;
}

void Grid::setDensity(float d){
    density = d;
}


void Grid::printGrid(char** grid){
    for(int i = 0; i < row; ++i){
        for(int j = 0; i < col; ++j){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

bool Grid::isEmpty(char** grid){
    int row;
    int col;
    for(int i = 0; i < row; ++i){
        for(int j = 0; i < col; ++j){
            if(grid[i][j] == 'X'){
                return false; //if there is an occupied cell then grid is not empty
            }
        }
    }
    return true;
}

bool Grid::isStablized(char** grid, char** shadowGrid){
    int row;
    int col;
    for(int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if(grid[i][j] != shadowGrid[i][j]){
                return false;
            }
        }
    }
    return true;
}
