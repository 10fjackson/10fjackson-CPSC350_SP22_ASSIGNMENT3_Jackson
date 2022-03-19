#include "ClassicMode.h"
//#include "Gamemode.h"

ClassicMode::ClassicMode(){
    neighbors = 0;
}

ClassicMode::~ClassicMode(){

}

//void ClassicMode::PlayClassicMode(){
//    ScanNeighbors();
//}

void ClassicMode::ScanNeighbors(){
    //Gamemode *g = new Gamemode();
    char grid[4][4] = { {'-','X','-','-'},
                        {'X','X','X','-'},
                        {'-','-','-','-'},
                        {'-','-','-','-'}};
    int row = 4;
    int col = 4;
    bool isNeighbor = false;
    int neighbors = 0;

    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){
        if(grid[i][j] == 'X'){


            if(grid[i-1][j-1] == 'X' && (i != 0 && j != 0)){
              //top left
              cout<<"scan neightbors detecteed top left"<<endl;
              neighbors++;
            }

            if(grid[i-1][j+1] == 'X' && (j != (col-1) && i !=0)){
              //top right
              cout<<"scan neightbors detecteed top right"<<endl;
              neighbors++;
            }

            if(grid[i+1][j+1] == 'X' && (j != (col-1) && i != (row-1))){
              //bottom right
              cout<<"scan neightbors detecteed bottom right"<<endl;
              neighbors++;
            }

            if(grid[i+1][j-1] == 'X' && (i != (row-1) && j!=0)){
              //bottom left
              cout<<"scan neightbors detecteed bottom left"<<endl;
              neighbors++;
            }

            if(grid[i][j-1] == 'X' && j!=0){
              //left
              cout<<"scan neightbors detecteed left"<<endl;
              neighbors++;
            }

            if(grid[i][j+1] == 'X' && j != (col-1)){
              //right
              cout<<"scan neightbors detecteed right"<<endl;
              neighbors++;
            }

            if(grid[i-1][j] == 'X' && i != 0){
              //top
              cout<<"scan neightbors detecteed top"<<endl;
              neighbors++;
            }

            if(grid[i+1][j] == 'X' && i != (col-1)){
              //bottom
              cout<<"scan neightbors detecteed bottom"<<endl;
              neighbors++;
            }
            cout<<neighbors<<endl;
            neighbors = 0;
        }
      }
    }


}
