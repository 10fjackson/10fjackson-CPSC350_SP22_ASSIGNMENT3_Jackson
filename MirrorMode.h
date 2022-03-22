#ifndef MIRRORMODE_H
#define MIRRORMODE_H
#include <iostream>
using namespace std;


class MirrorMode{
    public:
        MirrorMode();
        ~MirrorMode();

        char** PlayMirrorMode(char** grid);
        char** ScanNeighbors(char** grid);


    private:



};

#endif
