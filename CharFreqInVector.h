//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_CHARFREQINVECTOR_H
#define ALGORITMODEHUFFMAN_CHARFREQINVECTOR_H

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class CharFreqInVector
{
public:
    CharFreqInVector(vector<char>& charVec);
    ~CharFreqInVector();
    void clearVectors();
    void calculateFrequency();
    void calcFreqInCompressed();
    void displayFrequency();
    int convertStringToInt(string aString);
    vector<char> getEachChar(){return eachChar;}
    vector<int> getEachFrequency(){return eachFrequency;}
private:
    vector<char> charVector;
    vector<char> eachChar;
    vector<int>	 eachFrequency;
    static const int streamSize = 255;
};


#endif //ALGORITMODEHUFFMAN_CHARFREQINVECTOR_H
