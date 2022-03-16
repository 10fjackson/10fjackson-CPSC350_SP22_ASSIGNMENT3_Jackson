#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
  row = 0;
  col = 0;
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
void Grid::createGrid(string layout, int r, int c){
  row = r;
  col = c;

  if(layout == "random"){
    //num will be a 1 or 2, will decide whether there is an X in this space
    for(int i = 0; i < row;++i){
      for(int j = 0; j < col; ++j){
        int num = rand() % 2;
        if(num == 1){
          grid[i][j] = 'X';
          cout<<grid[i][j];
        }
        else{
          grid[i][j] = '-';
          cout<<grid[i][j];
        }
        num = 0;
      }
      cout<<endl;
    }

  }//end of random if statement

}
