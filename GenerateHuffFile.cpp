//
// Created by racso on 19/06/18.
//

#include "GenerateHuffFile.h"


GenerateHuffFile::GenerateHuffFile(vector<Node*> *aList, vector<char> vFile, string outFile, vector<char> cBytes, vector<int> freqs)
{
vectorFile = vFile;
outputFile = outFile;
myList = aList;
bitCounter = 0;
bitPosition = 128;
totalBitsInFile = 0;
charBytes = cBytes;
frequencies = freqs;
}

void GenerateHuffFile::writeHuffFile()
{

    fout.open(outputFile.c_str(), ios::binary);

    //diplay tree in file
    for(unsigned int i = 0; i < charBytes.size(); i++)
    {
        fout << charBytes[i];
        fout << frequencies[i];
        fout << ',';

    }
    fout << "00" << ','; //marker to mark the end of the tree in the file



    writeBitPortionToFile();


    fout.close();

}


void GenerateHuffFile::writeBits(vector<bool> bitVector,int index)
{

//	for(unsigned int i = 1; i < bitVector.size();i++)
//{
//cout << bitVector[i];
//	}
//cout << endl;

for(unsigned int i = 1; i < bitVector.size(); i++)
{
if(bitVector[i])
{
for(int j = 0; j < bitCounter; j++)
{
bitPosition = bitPosition/2;
}
dummyByte = dummyByte | bitPosition;
bitPosition = 128;
bitCounter++;
totalBitsInFile++;

}
else
{
bitCounter++;
totalBitsInFile++;


}
if(bitCounter == 8 || (index == vectorFile.size() - 1) && (i == bitVector.size() - 1))
{

fout << dummyByte;//cout dummy byte to a file
///cout << getBitsInChar(dummyByte);
bitCounter = 0;
dummyByte = dummyByte & 0;
}
}


}

string GenerateHuffFile::getBitsInChar(char dummyByte)
{
    int bitPosition = 128;
    string bits;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < i; j++)
        {
            bitPosition = bitPosition/2;
        }
        if((dummyByte & bitPosition) == bitPosition)
        {
            bits.push_back('1');
        }
        else
            bits.push_back('0');
        bitPosition = 128;


    }
    bits.push_back('\n');
    return bits;
}

void GenerateHuffFile::writeBitPortionToFile()
{

    bool inChild = false;
    Node *aNode;
    dummyByte = dummyByte & 0; //clear bit inside to zero

    for(unsigned int i = 0; i < vectorFile.size(); i++)
    {
        for(unsigned int j = 0; j < myList->size(); j++)
        {
            if(myList[0][j]->getMyChildrenSize() > 0)
            {
                aNode = myList[0][j]->searchCharByte(vectorFile[i]) ;
                writeBits(aNode->getBitVector(),i);

            }
        }
    }

    //cout << endl << totalBitsInFile << endl;


}