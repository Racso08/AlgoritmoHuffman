//
// Created by racso on 19/06/18.
//

#include "CharFreqInVector.h"

CharFreqInVector::CharFreqInVector(vector<char>& charVec)
{
    charVector = charVec;


}

void CharFreqInVector::displayFrequency()
{
    for(unsigned int i = 0; i < eachChar.size(); i++)
    {
        cout <<"char:" << eachChar[i] << " freq:" << eachFrequency[i] << endl;
    }
}


void CharFreqInVector::calcFreqInCompressed()
{
    string intString;
    int j = 0;
    int i = 0;

    while(1)
    {
        eachChar.push_back(' ');
        eachFrequency.push_back(0);
        eachChar[j] = charVector[i];
        i++;

        while(charVector[i] != ',')
        {
            intString.push_back(charVector[i]);
            i++;
        }
        i++;
        eachFrequency[j] = convertStringToInt(intString);

        intString.clear();

        if(eachChar[j] == '0' || eachFrequency[j] == 0)
        {
            eachChar.pop_back();
            eachFrequency.pop_back();
            break;
        }

        j++;

    }
}

int CharFreqInVector::convertStringToInt(string aString)
{
    int anInt;
    stringstream myStream;
    myStream.str(aString);
    myStream >> anInt;

    return anInt;
}

void CharFreqInVector::calculateFrequency()
{
    bool isAlreadyIn = false;
    unsigned int i = 0;
    unsigned int j = 0;

    for(i = 0; i < charVector.size(); i++)
    {
        for(j = 0; j < eachChar.size(); j++)
        {
            if(charVector[i] == eachChar[j])
            {
                eachFrequency[j]++;
                isAlreadyIn = true;
                break;
            }

        }
        if(!isAlreadyIn)
        {
            eachChar.push_back(charVector[i]);
            eachFrequency.push_back(1);
        }
        else
            isAlreadyIn = false;
    }
}

void CharFreqInVector::clearVectors()
{
    charVector.clear();
    eachChar.clear();
    eachFrequency.clear();

}

CharFreqInVector::~CharFreqInVector()
{
    clearVectors();
}