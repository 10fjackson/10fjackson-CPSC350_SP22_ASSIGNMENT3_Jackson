#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();

        void processMapFile(string fileName);

        int height;
        int width;
        string line;

    private:


};

#endif
