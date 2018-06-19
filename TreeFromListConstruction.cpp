//
// Created by racso on 19/06/18.
//

#include "TreeFromListConstruction.h"
#include <cassert>

TreeFromListConstruction::TreeFromListConstruction(vector<char> charByte, vector<int> frequency)
{


    for(unsigned int i = 0; i < charByte.size(); i++)
    {
        myList.push_back(new LeafNode(charByte[i], frequency[i]));
    }
    characterByte = charByte;

}

void TreeFromListConstruction::formTree()
{


    // set least to first element
    Node *temp = 0 ;
    int leastFrequency = myList[0]->getFrequencyNumber();
    int leastIndex = 0;
    int loopTwice = 0;
    int loopN = 0;


    while(myList.size() > 1 )
    {
        while(loopTwice < 2) //loop twice to get lowest two
        {
            for(unsigned int i = 0; i < myList.size(); i++)
            {

                if(myList[i]->getFrequencyNumber() < leastFrequency)//if we find a frequency in the list lower then our current least then set it to least
                {
                    leastIndex = i;
                    leastFrequency = myList[i]->getFrequencyNumber();

                }
            }

            ////			//cout << "the least frequncy is: " << leastfrequency << endl;

            if(myList[leastIndex]->getIsNode())
            {
                lowestTwoFreqs.push_back(new Node);

            }
            else
            {
                lowestTwoFreqs.push_back(new LeafNode(myList[leastIndex]->getCharacterByte()));

            }

            *lowestTwoFreqs[lowestTwoFreqs.size() - 1] = *myList[leastIndex];

            delete myList[leastIndex];
            myList.erase(myList.begin()+ leastIndex);

            if(myList.size() > 0)
            {
                leastFrequency = myList[0]->getFrequencyNumber();//initialize a few of these guys back
            }

            loopTwice++;
            leastIndex = 0;


        }

        myList.push_back (new Node(lowestTwoFreqs[lowestTwoFreqs.size() - 1], lowestTwoFreqs[lowestTwoFreqs.size() - 2]));


        loopN++;




        loopTwice = 0;
    }

    myList[0]->clearBitVector(); //clear the root node's bit vector so it will not contribute to the leaf node bit assignment


    for(unsigned int i = 0; i < myList.size(); i++)
    {
        myList[i]->ConstructBitVector();
    }

    /*for(unsigned int i = 0; i < myList.size(); i++)
    {
        myList[i]->displayNodeData();
    }*/
}

void TreeFromListConstruction::deleteMemory()
{
    for(unsigned int i = 0; i < myList.size(); i++)
    {

        delete myList[i];
    }

}

TreeFromListConstruction::~TreeFromListConstruction()
{
    deleteMemory();
    for(unsigned int i = 0; i < lowestTwoFreqs.size(); i++)//destroy list of lowestfreqs
    {
        delete lowestTwoFreqs[i];
    }
}
