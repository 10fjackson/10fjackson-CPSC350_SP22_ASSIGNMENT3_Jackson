#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>
using namespace std;


class ClassicMode{
    public:
        ClassicMode();
        ~ClassicMode();


        char** PlayClassicMode(char** grid);
        char** ScanNeighbors(char** grid);


    private:
        bool isNeighbor;
        int neighbors;


};

#endif
