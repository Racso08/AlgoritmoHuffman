//
// Created by racso on 19/06/18.
//

#include "FileLoader.h"

FileLoader::FileLoader(string fName)
{
    fileName = fName;
}

vector<char> FileLoader::loadFileIntoVector()
{

    ifstream fin;
    fin.open(fileName.c_str(), ios::binary);

    if(!fin)
    {
        cout << "unable to open file\n";
        exit(1);
    }

    char ch;
    while(fin.get(ch))
        fileVector.push_back(ch);



    fin.close();


    return fileVector;
}