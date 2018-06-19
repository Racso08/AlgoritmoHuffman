//
// Created by racso on 19/06/18.
//

#include "Decompressor.h"

Decompressor::Decompressor(vector<Node*> *aList, vector<char> vFile, string inFile, string outFile, unsigned int origFile)
{
vectorFile = vFile;
outputFileName = outFile;
inputFileName = inFile;
myList = aList;
originalFileSize = origFile;
}

void Decompressor::remakeFile()
{
    vector<char> eachChar;
    vector<char> eachFrequency;
    string intString;

    unsigned int j = 0;
    unsigned int i = 0;

    while(1)
    {

        eachChar.push_back(' ');
        eachFrequency.push_back(' ');
        eachChar[j] = vectorFile[i];
        i++;

        while(vectorFile[i] != ',')
        {
            intString.push_back(vectorFile[i]);

            i++;
        }
        i++;

        eachFrequency[j] = vectorFile[i];

        intString.clear();

        if(eachChar[j] == '0' || eachFrequency[j] == '0')
        {
            i = i + 3;
            uncompressChars(i);
            break;
        }

        j++;

    }

}

void Decompressor::uncompressChars(unsigned int i )
{
    int bitPosition = 128;
    unsigned int fileSize = 0;
    Node *temp = &*myList[0][0];
    int bitCounter = 0;
    vector<bool> bitVector;
    ofstream fout;

    fout.open(outputFileName.c_str(), ios::binary);


    for(i; i < vectorFile.size();)
    {

        for(int j = 0; j < bitCounter; j++)
        {
            bitPosition = bitPosition/2;
        }

        if((vectorFile[i] & bitPosition) == bitPosition)
        {
            bitVector.push_back(true);

            if(temp->getMyChildrenSize() > 0)
            {
                temp = temp->getMyChildrenElement(0);

                if(temp->getMyChildrenSize() == 0)
                {

                    //if(fileSize < originalFileSize)
                    //{
                    //	cout << temp->getCharacterByte();
                    fout << temp->getCharacterByte();
                    fileSize++;
                    //	}
                    temp = &*myList[0][0];
                }
            }
        }
        else
        {
            bitVector.push_back(false);
            if(temp->getMyChildrenSize() > 0)
            {
                temp = temp->getMyChildrenElement(1);

                if(temp->getMyChildrenSize() == 0)
                {

                    if(fileSize < originalFileSize)
                    {
                        //cout << temp->getCharacterByte();
                        fout << temp->getCharacterByte();
                        fileSize++;
                    }
                    temp = &*myList[0][0];
                }

            }
        }

        bitPosition = 128;
        bitCounter++;

        if(bitCounter == 8)
        {

            //cout << dummyByte;//cout dummy byte to a file

            bitCounter = 0;
            i++;
        }
    }

//	cout << endl;
    int c = 0;
    for(unsigned int i = 0; i < bitVector.size(); i++)
    {

        //cout <<	bitVector[i];
        c++;
        if(c == 8)
        {
            //cout << " ";
            c = 0;
        }

    }

    fout.close();

}