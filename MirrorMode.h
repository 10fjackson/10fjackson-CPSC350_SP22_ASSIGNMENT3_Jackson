#ifndef MIRRORMODE_H
#define MIRRORMODE_H
#include <iostream>
using namespace std;


class MirrorMode{
    public:
        MirrorMode();
        ~MirrorMode();

        char** PlayMirrorMode(char** grid, int row, int col);
        char** ScanNeighbors(char** grid, int row, int col);


    private:



};

#endif
