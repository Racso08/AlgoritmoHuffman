//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_TREEFROMLISTCONSTRUCTION_H
#define ALGORITMODEHUFFMAN_TREEFROMLISTCONSTRUCTION_H

#include "LeafNode.h"

class TreeFromListConstruction
{
public:
    TreeFromListConstruction(vector<char> charByte, vector<int> frequency);
    ~TreeFromListConstruction();
    vector<Node*> *getTree(){return &myList;}
    void formTree();
    void deleteMemory();
//	vector<Node> *returnTree(){return &tree;}
private:
    vector<Node*> myList;
    //vector<Node> tree;
    vector<Node*> lowestTwoFreqs;
    vector<char> lowestTwoChars;
    vector<char> characterByte;

};

#endif //ALGORITMODEHUFFMAN_TREEFROMLISTCONSTRUCTION_H
