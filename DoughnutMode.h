#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H
#include <iostream>
using namespace std;


class DoughnutMode{
    public:
        DoughnutMode();
        ~DoughnutMode();

        char** PlayDoughnutMode(char** grid, int row, int col);
        char** ScanNeighbors(char** grid, int row, int col);


    private:



};

#endif
