//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_FILELOADER_H
#define ALGORITMODEHUFFMAN_FILELOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileLoader
{
public:
    FileLoader(string fName);
    ~FileLoader(){;}
    vector<char> loadFileIntoVector();
    vector<char> fileVector;

private:

    string fileName;

};

#endif //ALGORITMODEHUFFMAN_FILELOADER_H
