#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

class Grid{
public:
  Grid();
  Grid(int r, int c);
  ~Grid();
  void Test();
  int row;
  int col;
private:
  char *grid;
};



#endif
