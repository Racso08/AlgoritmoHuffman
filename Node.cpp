//
// Created by racso on 19/06/18.
//

#include "Node.h"

Node::Node(Node* child1, Node* child2)
{
    frequencyNumber = child1->frequencyNumber + child2->frequencyNumber; //need the parent to have the children's combine frequency
    bitOn = false;
    null = false;
    isNode = true;
    child1->bitOn = 1; //set the bit of the children left = child1 which = 1 and right = child2 which = 0
    child2->bitOn = 0;
    myChildren.push_back(child1);
    myChildren.push_back(child2);

}
void Node::ConstructBitVector()
{
    for(int unsigned i = 0; i < myChildren.size(); i++)
    {
        myChildren[i]->bitVector = bitVector;
        myChildren[i]->bitVector.push_back(bitOn); //give the current bit vector to the child
        myChildren[i]->ConstructBitVector();
    }

}
void Node::displayNodeData()
{
    cout << "freq: " << frequencyNumber << endl;
    for(int unsigned i = 0; i < myChildren.size(); i++)
    {
        cout << "child" << i << ": ";
        myChildren[i]->displayNodeData();

    }

}

Node* Node::searchCharByte(char target)
{
    Node *aNode = this;
    if(aNode->getCharacterByte() == target)
        return this;

    for(int unsigned i = 0; i < myChildren.size(); i++)
    {
        aNode = myChildren[i]->searchCharByte(target);
        if(aNode->getCharacterByte() == target)
            break;
    }

    return aNode;

}

void Node::displayNodeData(ofstream *fout)
{
//	*fout << "freq: " << frequencyNumber << "\n";
    for(int unsigned i = 0; i < myChildren.size(); i++)
    {
        //myChildren[i]->bitVector = bitVector;
        //myChildren[i]->bitVector.push_back(bitOn); //give the current bit vector to the child
        //*fout << "child" << i << ": ";
        myChildren[i]->displayNodeData(&*fout);

    }
}
