//
// Created by racso on 19/06/18.
//

#include "LeafNode.h"

LeafNode::LeafNode(char character, int frequency)
{
    characterByte = character;
    frequencyNumber = frequency;
    isNode = false;
}

LeafNode::LeafNode(char character)
{
    characterByte = character;
}

void LeafNode::ConstructBitVector()
{
    bitVector.push_back(bitOn); //give its own bit to the bit vector
}

void LeafNode::displayNodeData()
{

    cout <<"char:" << characterByte << " freq:" << frequencyNumber << endl;


    cout << "The bits assigned to this leaf node are: ";

    for(int unsigned i = 1; i < bitVector.size(); i++) //display the bits assigned to the leaves and start on 1 to not include the root node's bit
    {
        cout << bitVector[i];

    }
    cout << endl;


}

void LeafNode::displayNodeData(ofstream *fout)
{

    *fout << characterByte << frequencyNumber << ',';

    /*bitVector.push_back(bitOn); //give its own bit to the bit vector

    *fout << "The bits assigned to this leaf node are: ";

    for(int unsigned i = 1; i < bitVector.size(); i++) //display the bits assigned to the leaves and start on 1 to not include the root node's bit
    {
        //cout << "\n bit Vector size is:" << bitVector.size() << endl;
        *fout << bitVector[i];

    }
    *fout << endl;*/


}