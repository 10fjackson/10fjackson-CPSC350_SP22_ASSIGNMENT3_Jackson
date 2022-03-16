#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>
using namespace std;


class ClassicMode{
    public:
        ClassicMode();
        ~ClassicMode();


        void PlayClassicMode();
        void ScanNeighbors();


    private:
        int row;
        int col;
        bool isNeighbor;
        int neighbors;


};

#endif
