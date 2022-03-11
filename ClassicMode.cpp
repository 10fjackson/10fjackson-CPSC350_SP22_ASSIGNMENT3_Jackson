#include "GameOfLife.h"

ClassicMode::ClassicMode(){

}

ClassicMode::~ClassicMode(){

}

int ClassicMode::ScanNeighbors(Grid grid){
    int neighbors = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int x = i - 1; x <= i +1; x++){ //check row above and below
                for(int y = j + 1; y <= j + 1; y++){ //check column above and below
                    if((x != 0) || (x != i) || (y != 0) || (y != j)){
                        
                    }
                }
            }
        }
    }
}
