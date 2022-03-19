#include "FileProcessor.h"
#include "Grid.h"
#include <exception>

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}

void FileProcessor::processMapFile(string fileName) {

    ifstream readFile (fileName);

    if(!readFile.is_open()) {
        cout << "Unable to open file";
    }
     //open the file to read
    string h;
    string w;
    getline(readFile, h);
    getline(readFile, w);
    int height = stoi(h);
    int width = stoi(w);
    // cout << height;
    // cout << width;
    Grid *g = new Grid(height, width); //create grid

    char** grid = g->grid;

    for(int i = 0; i < height; ++i){
        getline(readFile, line);
        for(int j = 0; j < width; ++ j){
            grid[i][j] = line[j];
            cout << line[j] << endl;
        }
    }
    readFile.close();
}

void FileProcessor::writeOutputFile(string outputFilePath){
    ofstream writeFile;
    writeFile.open(outputFilePath);
    Grid *g;
    char** grid = g -> grid;
    if(!writeFile.is_open()){
        cout << "Unable to open file";
    }
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            writeFile << grid[i][j];
        }
    }
    writeFile.close();
}
