#ifndef CLASSICMODE_H
#define CLASSICMODE_H
#include <iostream>


class ClassicMode{
    public:
        ClassicMode();
        ~ClassicMode();


        int ScanNeighbors(Grid grid);
        bool CheckCell(Grid grid, int x, int y);



    private:
        int row;
        int col;


};

#endif
