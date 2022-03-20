#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

class Grid{
public:
  Grid();//construcor
  Grid(int r, int c);//overloaded constructor
  ~Grid();//garbage collection
  void Test();//testing the method
  void createGrid(string layout);
  void printGrid();

  //accessors
  char** getGrid();
  int getRow();
  int getCol();

  //modifiers
  void setGrid(char** grid);
  void setRow(int row);
  void setCol(int col);
  void setDensity(float density);


  bool isEmpty();
  bool isStablized();

  int row;//number o rows
  int col;//number of columns
  float density;
  char **grid;//grid for the experiment
private:

};



#endif
