//
//  BinaryTree.h
//  Euler18
//
//  Created by M.A. de Vos on 22-08-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#ifndef __Euler18__BinaryTree__
#define __Euler18__BinaryTree__

#include "Node.hpp"

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    
    void addRoot(int value);
    bool isEmpty();
    int getSize();
    Node *getRoot();
    bool isRoot(Node *node);
    bool hasLeftChild(Node *node);
    bool hasRightChild(Node *node);
    bool isLeftChild(Node *node);
    bool isRightChild(Node *node);
    bool hasParent(Node *node);
    bool isExternal(Node *node);
    bool isInternal(Node *node);
    
    void insertLeft(Node *node, int value);
    void insertRight(Node *node, int value);
    
    Node *getLeftChild(Node *node);
    Node *getRightChild(Node *node);
    Node *getParent(Node *node);
    
    int replaceElement(Node *node, int newValue);
    void swapElements(Node *node1, Node *node2);
    
    int depth(Node *node);
    int nodeSize(Node *node);

private:
    Node *root;
    int size;
};

#endif /* defined(__Euler18__BinaryTree__) */
