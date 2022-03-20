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
            // cout << line[j] << endl;
        }
    }
    readFile.close();
}

void FileProcessor::writeOutputFile(string outputFilePath, int generation){
    ofstream writeFile;
    writeFile.open(outputFilePath);
    //get future grid
    if(!writeFile.is_open()){
        cout << "Unable to open file";
    }
    writeFile << "Generation " << generation << endl;
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            cout << grid[i][j]<< endl;
            writeFile << grid[i][j];
        }
    }
    writeFile << endl;
    writeFile.close();
}
