//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_DECOMPRESSOR_H
#define ALGORITMODEHUFFMAN_DECOMPRESSOR_H

#include "LeafNode.h"

class Decompressor
{
public:
    Decompressor(vector<Node*> *aList, vector<char> vFile, string inFile, string outFile, unsigned int origFile);
    void remakeFile();
    void uncompressChars(unsigned int i);

private:
    vector<char> vectorFile;
    unsigned int originalFileSize;
    string outputFileName;
    string inputFileName;
    vector<Node*> *myList;
    ofstream fout;
    ifstream infile;

};

#endif //ALGORITMODEHUFFMAN_DECOMPRESSOR_H
