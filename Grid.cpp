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
void Grid::createGrid(string layout){
  int row = this->row;
  // cout << "Row :" << row << endl;
  int col = this->col;
  // cout << "Col :" << col << endl;
  float density = 1/this->density;
  // cout << "Density :" << density << endl;
  int actualx;
  int numx = ((row*col)/density);
  if(layout == "random"){
    //num will be a 1 or 2, will decide whether there is an X in this space
    for(int i = 0; i < row;++i){
      for(int j = 0; j < col; ++j){
        int num = rand() % 2;
        if(num == 1){
          grid[i][j] = 'X';
          cout<<grid[i][j];
          actualx++;
        }
        else{
          grid[i][j] = '-';
          cout<<grid[i][j];
        }
        num = 0;
      }
      cout<<endl;
    }
    if(actualx<numx){
      while(actualx != numx){
          int r = rand() % (row-1);
          int c = rand() % (col-1);
          if(grid[r][c] == 'X'){
            grid[r][c] = '-';
            actualx++;
          }
        }
    }
    if(actualx>numx){
      while(actualx != numx){
          int r = rand() % (row-1);
          int c = rand() % (col-1);
          if(grid[r][c] == '-'){
            grid[r][c] = 'X';
            actualx--;
          }
        }
    }
  }//end of random if statement

}

char** Grid::getGrid(){
    return grid;
}

int Grid::getRow(){
    return row;
}

int Grid::getCol(){
    return col;
}

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


void Grid::printGrid(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; i < col; ++j){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

bool Grid::isEmpty(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; i < col; ++j){
            if(grid[i][j] == 'X'){
                return false;
            }
        }
    }
    return true;
}

bool Grid::isStablized(){
    // for(int i = 0; i < row; ++i){
    //     for (int j = 0; j < col; ++j){
    //         // if(grid[i][j] != futureGrid[i][j]){
    //         //     return false;
    //         }
    //     }
    // }
    // return true;
}
