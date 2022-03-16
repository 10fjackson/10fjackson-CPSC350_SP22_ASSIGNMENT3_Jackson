// #include "ClassicMode.h"
//
// ClassicMode::ClassicMode(){
//     int neighbors = 0;
// }
//
// ClassicMode::~ClassicMode(){
//
// }
//
// int ClassicMode::ScanNeighbors(){
//     char grid[4][4] = { {'-','-','-','-'},
//                         {'-','-','-','-'},
//                         {'-','-','X','-'},
//                         {'-','-','-','-'}};
//     int row = 4;
//     int col = 4;
//     bool isNeighbor = false;
//     int neighbors = 0;
//
//     for(int i = row - 1; i <= row + 1; ++i){
//         for(int j = col - 1; j <= col + 1; ++j){
//             cout << grid[i][j] << endl;
//                 if(i < 0 || j < 0 || i == row || j == col){
//                     continue;
//                 }
//                 else if(grid[i][j] == 'X' && !(i == row && j == col)){
//                     neighbors++;
//                     cout << neighbors << endl;
//                 }
//         }
//     }
//     return neighbors;
// }
