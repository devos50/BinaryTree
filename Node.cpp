//
//  Node.cpp
//  Euler18
//
//  Created by M.A. de Vos on 22-08-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include "Node.hpp"

// constructors
Node::Node()
{
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
    value = 0;
}

Node::Node(int nodeValue)
{
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
    value = nodeValue;
}

Node::Node(int nodeValue, Node *nodeParent, Node *nodeLeft, Node *nodeRight)
{
    leftChild = nodeLeft;
    rightChild = nodeRight;
    parent = nodeParent;
    value = nodeValue;
}

Node *Node::getRightChild()
{
    return rightChild;
}

Node *Node::getLeftChild()
{
    return leftChild;
}

Node *Node::getParent()
{
    return parent;
}

int Node::getValue()
{
    return value;
}

void Node::setLeftChild(Node *child)
{
    leftChild = child;
    child->setParent(this);
}

void Node::setRightChild(Node *child)
{
    rightChild = child;
    child->setParent(this);
}

void Node::setParent(Node *newParent)
{
    parent = newParent;
}

void Node::setValue(int newValue)
{
    value = newValue;
}