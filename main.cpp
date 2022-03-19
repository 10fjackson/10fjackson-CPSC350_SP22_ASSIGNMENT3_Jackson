#include "Grid.h"
#include "Gamemode.h"
#include "ClassicMode.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
  // Grid *g = new Grid(8,8);
  // g->Test();
  // return 0;

  int typeOfWorld;
  int row;
  int col;
  double density;
  string userInput;
  string inputFilePath;
  string outputFilePath;
  int outputType;
  int gamemode;

  Gamemode *g = new Gamemode();
  FileProcessor *p = new FileProcessor();

  cout << "Would you like to provide a map file for the world or to generate a random world?" << endl;
  cout << "Enter 0 to provide a map file or 1 for a random world" << endl;
  cin >> typeOfWorld;
  getline(cin, userInput);
  if(typeOfWorld == 1){ //if they want a random world
      cout << "Enter the number of rows you would like in your world:" << endl;
      cin >> row;
      getline(cin, userInput);
      // cout << row << endl;

      cout << "Enter the number of columns you would like in your world:" << endl;
      cin >> col;
      getline(cin, userInput);
      // cout << col << endl;

      cout << "Enter the density of the population in decimals (0.0 - 1.0)" << endl;
      cin >> density;
      getline(cin, userInput);
      // cout << density << endl;

      //generate random grid

  } else if (typeOfWorld == 0){
      cout << "Enter the file path to the map file:" << endl;
      cin >> inputFilePath;
      getline(cin, userInput);
      p -> processMapFile(inputFilePath);
      //cout << filePath << endl;

      //read in file and create world
  } else {
      cout << "Invalid choice of world" << endl;
  }

  cout << "Enter the boundary type you would like to play" << endl;
  cout << "0 for classic mode" << endl;
  cout << "1 for doughnut mode" << endl;
  cout << "2 for mirror mode" << endl;
  cin >> gamemode;
  getline(cin, userInput);
  g -> SetGamemode(gamemode); //set gamemode in gamemode class
  g -> PlayGame();

  cout << "If would you like a pause between generations enter 0" << endl;
  cout << "If you would like to press Enter to go to the next generation enter 1" << endl;
  cout << "If you would like to output everything to a file enter 2" << endl;
  cin >> outputType;
  getline(cin, userInput);
  if(outputType == 0){

  } else if (outputType == 1){

  } else if (outputType == 2){
      cout << "Enter the file you would like to output to" << endl;
      cin >> outputFilePath;
      getline (cin, userInput);


  } else {
      cout << "Invalid output type" << endl;
  }

}
