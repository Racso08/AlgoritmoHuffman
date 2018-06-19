//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_GENERATEHUFFFILE_H
#define ALGORITMODEHUFFMAN_GENERATEHUFFFILE_H

#include "LeafNode.h"
#include "string"
class GenerateHuffFile
{
public:
    GenerateHuffFile(vector<Node*> *aList, vector<char> vFile, string outPutFile,vector<char> charBytes, vector<int> frequencies);
    void writeHuffFile();//writes the true and bits to file
    void writeTreePortionToFile();//writes the tree into a file
    void writeBitPortionToFile();//writes the bits to a file
    void writeBits(vector<bool> bitVector,int i);
    void convertBoolVecToBits();//turns the boolean vector representing bits to real bits to write to file

    string getBitsInChar(char dummyByte);
private:
    vector<Node*> *myList;
    vector<char> vectorFile;
    vector<char> charBytes ;
    vector<int> frequencies ;
    string outputFile;
    ofstream fout;
    char dummyByte;
    int bitCounter;
    int bitPosition;
    int totalBitsInFile;
    static const int bitsInAByte = 8;

};

#endif //ALGORITMODEHUFFMAN_GENERATEHUFFFILE_H
