//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_NODE_H
#define ALGORITMODEHUFFMAN_NODE_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Node
{
public:
    Node(){isNode = false;}
    ~Node(){};
    Node(Node* child1, Node* child2);

    int getFrequencyNumber(){return frequencyNumber;}
    char getMyChildrenElementChar(int index) { return myChildren[index]->getCharacterByte();}
    unsigned int getMyChildrenSize(){ return myChildren.size();}
    void setBitVector(vector <bool> bitVect){bitVector = bitVect;}
    void clearBitVector(){bitVector.clear();}
    void setNull(bool bNull){null = bNull;}
    bool getNull(){return null;}
    bool getIsNode(){return isNode;}
    virtual void displayNodeData();
    virtual char getCharacterByte(){return '\0';}
    virtual void displayNodeData(ofstream *fout);
    virtual Node *searchCharByte(char target);
    virtual void ConstructBitVector();
    vector<bool> getBitVector(){return bitVector;}
    Node *getMyChildrenElement(int index) { return &*myChildren[index];}


protected:
    int frequencyNumber;
    bool bitOn;
    bool isNode;
    bool null;
    string printedData;
    vector <bool> bitVector;

private:
    vector <Node*> myChildren;


};



#endif //ALGORITMODEHUFFMAN_NODE_H
