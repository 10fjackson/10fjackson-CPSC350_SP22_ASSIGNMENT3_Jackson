#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>
using namespace std;


class ClassicMode{
    public:
        ClassicMode();
        ~ClassicMode();


        char** PlayClassicMode(char** grid, int row, int col);
        char** ScanNeighbors(char** grid, int row, int col);


    private:
        bool isNeighbor;
        int neighbors;


};

#endif
