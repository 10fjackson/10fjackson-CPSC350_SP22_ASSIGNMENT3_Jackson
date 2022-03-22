#include "Grid.h"
#include "Gamemode.h"
#include "ClassicMode.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
using namespace std;

//We are using a late day for this assignment

int main(int argc, char** argv){
  // Grid *g = new Grid(8,8);
  // g->Test();
  // return 0;

  int typeOfWorld;
  int row;
  int col;
  float density;
  string userInput;
  string inputFilePath;
  string outputFilePath;
  int outputType;
  int gamemode;
  int generation;

  Grid *gr;
  Gamemode *g = new Gamemode();
  FileProcessor *p = new FileProcessor();
  char** grid;
  char** shadowGrid;

  cout << "Would you like to provide a map file for the world or to generate a random world?" << endl;
  cout << "Enter 0 to provide a map file or 1 for a random world" << endl;
  cin >> typeOfWorld;
  getline(cin, userInput);
  if(typeOfWorld == 1){ //if they want a random world
      cout << "Enter the number of rows you would like in your world:" << endl;
      cin >> row;//store row variable
      getline(cin, userInput);
      //gr->setRow(row); //set the row in the grid class
      // cout << row << endl;

      cout << "Enter the number of columns you would like in your world:" << endl;
      cin >> col; //store column variable
      getline(cin, userInput);
      //gr->setCol(col); //set the column in the grid class
      // cout << col << endl;

      cout << "Enter the density of the population in decimals (0.0 - 1.0)" << endl;
      cin >> density; //store density variable
      getline(cin, userInput);
      //gr->setDensity(density); //set the density in the grid class
      // cout << density << endl;
      gr = new Grid(row, col);
      cout<<"54"<<endl;
      gr->setRow(row);
      gr->setCol(col);
      grid = gr->createGrid("random", row, col, density);

      cout<<"56"<<endl;//generate random cells
      shadowGrid = gr->createShadowGrid(grid); //create shadow grid to copy grid
      shadowGrid = grid;

  } else if (typeOfWorld == 0){
      cout << "Enter the file path to the map file:" << endl;
      cin >> inputFilePath; //store file path
      getline(cin, userInput);
      grid = p -> processMapFile(inputFilePath); //store processed grid into grid variable
      shadowGrid = gr->createShadowGrid(grid); //make shadow grid
      cout << grid << endl;
      //cout << filePath << endl;

      //read in file and create world
  } else {
      cout << "Invalid choice of world" << endl;
  }

  cout << "Enter the boundary type you would like to play" << endl;
  cout << "0 for classic mode" << endl;
  cout << "1 for doughnut mode" << endl;
  cout << "2 for mirror mode" << endl;
  cin >> gamemode; //store gamemode variable
  getline(cin, userInput);
  g -> SetGamemode(gamemode); //set gamemode in gamemode class
  grid = g -> PlayGame(grid); //pass grid through play game class
  // gr -> printGrid(grid);

  cout << "If would you like a pause between generations enter 0" << endl;
  cout << "If you would like to press Enter to go to the next generation enter 1" << endl;
  cout << "If you would like to output everything to a file enter 2" << endl;
  cin >> outputType; //store output type
  getline(cin, userInput);

  while(!(gr->isEmpty(grid) || gr->isStablized(grid, shadowGrid))){ //check if grid is empty or stabilized
      if(outputType == 0){
          cout << "Generation " << generation << endl;
          gr -> printGrid(grid); //print grid
          system("pause"); //pause the system
          shadowGrid = grid; //store current grid into shadow grid
          grid = g -> PlayGame(grid); //play next game and store into grid
      } else if (outputType == 1){
          cout << "Generation " << generation << endl;
          gr -> printGrid(grid); //print grid
          cout << "Press Enter to go to the next generation" << endl;
          getline(cin, userInput);
              // if(userInput == '\n'){
              //     //print grid
              // } else {
              //     continue;
              // }
          shadowGrid = grid; //store current grid into shadow grid
          grid = g -> PlayGame(grid); //play next game and store into grid
      } else if (outputType == 2){
          cout << "Enter the file you would like to output to" << endl;
          getline (cin, userInput);
          p -> writeOutputFile(userInput, generation, grid); //output grid into file
          shadowGrid = grid; //store current grid into shadow grid
          grid = g -> PlayGame(grid); //play next game and store into grid

      } else {
          cout << "Invalid output type" << endl;
      }
      generation++;
  }
}
