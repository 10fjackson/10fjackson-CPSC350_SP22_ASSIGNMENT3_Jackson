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
  int row;//number o rows
  int col;//number of columns
private:
  char **grid;//grid for the experiment
};



#endif
