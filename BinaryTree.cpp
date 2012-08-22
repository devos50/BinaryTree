//
//  BinaryTree.cpp
//  Euler18
//
//  Created by M.A. de Vos on 22-08-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include "BinaryTree.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL;
    size = 0;
}

void BinaryTree::addRoot(int value)
{
    if(isEmpty())
    {
        Node *newRoot = new Node(value);
        root = newRoot;
        size++;
    }
    else
    {
        cout << "Tree is not empty - not adding the new root" << endl;
    }
}

bool BinaryTree::isEmpty()
{
    return (size == 0);
}

int BinaryTree::getSize()
{
    return size;
}

Node *BinaryTree::getRoot()
{
    if(isEmpty())
    {
        cout << "Tree is empty - returning NULL" << endl;
        return NULL;
    }
    else
    {
        return root;
    }
}

bool BinaryTree::isRoot(Node *node)
{
    return (node == root);
}

bool BinaryTree::hasLeftChild(Node *node)
{
    return (node->getLeftChild() != NULL);
}

bool BinaryTree::hasRightChild(Node *node)
{
    return (node->getRightChild() != NULL);
}

bool BinaryTree::isLeftChild(Node *node)
{
    Node *parent = node->getParent();
    return (parent->getLeftChild() == node);
}

bool BinaryTree::isRightChild(Node *node)
{
    Node *parent = node->getParent();
    return (parent->getRightChild() == node);
}

bool BinaryTree::hasParent(Node *node)
{
    return (node->getParent() != NULL);
}

bool BinaryTree::isExternal(Node *node)
{
    return (node->getLeftChild() == NULL && node->getRightChild() == NULL);
}

bool BinaryTree::isInternal(Node *node)
{
    return (node->getLeftChild() != NULL || node->getRightChild() != NULL);
}

void BinaryTree::insertLeft(Node *node, int value)
{
    if(node->getLeftChild() != NULL)
    {
        cout << "Node already has a left child! Returning..." << endl;
        return;
    }
    
    Node *newNode = new Node(value);
    node->setLeftChild(newNode);
    size++;
}

void BinaryTree::insertRight(Node *node, int value)
{
    if(node->getRightChild() != NULL)
    {
        cout << "Node already has a right child! Returning..." << endl;
        return;
    }
    
    Node *newNode = new Node(value);
    node->setRightChild(newNode);
    size++;
}

Node *BinaryTree::getLeftChild(Node *node)
{
    if(hasLeftChild(node))
    {
        return node->getLeftChild();
    }
    else
    {
        cout << "Node does not have a left child, returning NULL" << endl;
        return NULL;
    }
}

Node *BinaryTree::getRightChild(Node *node)
{
    if(hasRightChild(node))
    {
        return node->getRightChild();
    }
    else
    {
        cout << "Node does not have a right child, returning NULL" << endl;
        return NULL;
    }
}

Node *BinaryTree::getParent(Node *node)
{
    if(hasParent(node))
    {
        return node->getParent();
    }
    else
    {
        cout << "Node does not have a parent, returning NULL" << endl;
        return NULL;
    }
}

int BinaryTree::replaceElement(Node *node, int newValue)
{
    int oldValue = node->getValue();
    node->setValue(newValue);
    return oldValue;
}

void BinaryTree::swapElements(Node *node1, Node *node2)
{
    int value = replaceElement(node1, node2->getValue());
    node2->setValue(value);
}

int BinaryTree::depth(Node *node)
{
    if(node == root) return 0;
    else return 1 + depth(node->getParent());
}

int BinaryTree::nodeSize(Node *node)
{
    if(hasLeftChild(node) && hasRightChild(node)) return 1 + nodeSize(node->getLeftChild()) + nodeSize(node->getRightChild());
    else if(hasLeftChild(node) && !hasRightChild(node)) return 1 + nodeSize(node->getLeftChild());
    else if(!hasLeftChild(node) && hasRightChild(node)) return 1 + nodeSize(node->getRightChild());
    else return 1;
}