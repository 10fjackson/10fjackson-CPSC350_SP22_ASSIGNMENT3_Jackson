#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
  row = 0;
  col = 0;
  //grid = new char[0][0];
}
Grid::Grid(int r, int c){
  row = r;
  col = c;
  grid = new char*[row];
  for(int i = 0; i < row; ++i) {
    grid[i] = new char[col];
  }
}
Grid::~Grid(){
  cout<<"Deleting Grid"<<endl;
  for(int i = 0; i < row; ++i) {
    delete [] grid[i];
  }
  delete [] grid;
}
void Grid::Test(){
  for(int i = 0; i < row;++i){
    for(int j = 0; j < col; ++j){
      grid[i][j] = 'X';
      cout<<grid[i][j];
    }
    cout<<endl;
  }
}
