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

    for(int i = 0; i < height; ++i){
        getline(readFile, line);
        for(int j = 0; j < width; ++ j){
            grid[i][j] = line[j];
            cout << line[j] << endl;
        }
    }
    cout << grid << end;
    readFile.close();
}
