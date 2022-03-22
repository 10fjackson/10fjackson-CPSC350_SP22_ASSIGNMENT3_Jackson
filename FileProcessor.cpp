#include "FileProcessor.h"
#include "Grid.h"
#include <exception>

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}

char** FileProcessor::processMapFile(string fileName) {

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
    g->setRow(height);
    g->setCol(width);

    char** grid = g->getGrid();

    for(int i = 0; i < height; ++i){
        getline(readFile, line);
        for(int j = 0; j < width; ++ j){
            grid[i][j] = line[j];
            // cout << grid[i][j] << endl;
        }
    }
    return grid;
    readFile.close();
}

void FileProcessor::writeOutputFile(string outputFilePath, int generation){
    ofstream writeFile(outputFilePath);
    Grid g;
    char** grid = g.grid; //access grid
    int row = g.row; //access row
    int col = g.col; //access column
    cout << row << col << endl;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++ j){
            cout << grid[i][j] << endl;
        }
    }
    if(!writeFile.is_open()){ //Check if file is open
        cout << "Unable to open file";
    }
    writeFile << "Generation " << generation << endl;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            // cout << grid[i][j]<< endl;
            writeFile << grid[i][j]; //Write each cell to file
        }
    }
    writeFile << endl;
    writeFile.close();
}
