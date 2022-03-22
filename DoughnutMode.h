#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H
#include <iostream>
using namespace std;


class DoughnutMode{
    public:
        DoughnutMode();
        ~DoughnutMode();

        char** PlayDoughnutMode(char** grid);
        char** ScanNeighbors(char** grid);


    private:



};

#endif
