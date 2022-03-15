#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>


class ClassicMode{
    public:
        ClassicMode();
        ~ClassicMode();


        int ScanNeighbors(Grid grid);


    private:
        int row;
        int col;


};

#endif
