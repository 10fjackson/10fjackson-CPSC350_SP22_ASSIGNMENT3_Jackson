#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>
using namespace std;


class ClassicMode{
    public:
        ClassicMode();
        ~ClassicMode();


        void PlayClassicMode();
        void ScanNeighbors(char** grid);


    private:
        bool isNeighbor;
        int neighbors;


};

#endif
