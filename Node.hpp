//
//  Node.h
//  Euler18
//
//  Created by M.A. de Vos on 22-08-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#ifndef __Euler18__Node__
#define __Euler18__Node__

#include <iostream>

using namespace std;

class Node
{
private:
    int value;
    Node *leftChild;
    Node *rightChild;
    Node *parent;
    
public:
    Node();
    Node(int nodeValue);
    Node(int nodeValue, Node *nodeParent, Node *nodeLeft, Node *nodeRight);
    
    Node *getLeftChild();
    Node *getRightChild();
    Node *getParent();
    int getValue();
    
    void setLeftChild(Node *child);
    void setRightChild(Node *child);
    void setParent(Node *newParent);
    void setValue(int newValue);
};

#endif /* defined(__Euler18__Node__) */
