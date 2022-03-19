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
      //fills the selected row/column spot with a char
      grid[i][j] = 'X';
      //prints out the char in that spot
      cout<<grid[i][j];
    }
    cout<<endl;
  }
}

// Grid Grid::GetGrid(){
//     return grid;
// }
