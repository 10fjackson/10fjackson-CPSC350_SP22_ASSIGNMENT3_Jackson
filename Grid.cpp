#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
  row = 0;
  col = 0;
  grid = new char[0][0];
}
Grid::Grid(int r, int c){
  row = r;
  col = c;
  grid = new char[row][col];
}
Grid::~Grid(){
  cout<<"Deleting Grid";
  delete[][] grid;
}
void Grid::Test(){
  for(int i = 0; i < row;++i){
    for(int j = 0; j < col; ++j){
      grid[i][j] = 'X';
      cout<<grid[i][j]<<endl;
    }
  }
}
