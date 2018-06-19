//
// Created by racso on 19/06/18.
//

#ifndef ALGORITMODEHUFFMAN_LEAFNODE_H
#define ALGORITMODEHUFFMAN_LEAFNODE_H

#include "Node.h"

class LeafNode : public Node
{
public:
    LeafNode(){;}
    LeafNode(char character, int frequency);
    LeafNode(char character);
    ~LeafNode(){isNode = false;}
    virtual char getCharacterByte(){return characterByte;}
    virtual void displayNodeData();
    virtual void ConstructBitVector();
    virtual void displayNodeData(ofstream *fout);

private:
    char characterByte;

};

#endif //ALGORITMODEHUFFMAN_LEAFNODE_H
