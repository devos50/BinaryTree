//
//  NodeTest.cpp
//  Euler18
//
//  Created by M.A. de Vos on 22-08-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include "NodeTest.hpp"
#include "Node.hpp"

using namespace std;

int testNum = 1;

void testEquality(void *obj1, void *obj2)
{
    if(obj1 == obj2) cout << "Test " << testNum << ": passed" << endl;
    else cout << "Test " << testNum << ": failed" << endl;
    testNum++;
}

void testEqualityInts(int a, int b)
{
    if(a == b) cout << "Test " << testNum << ": passed" << endl;
    else cout << "Test " << testNum << ": failed" << endl;
    testNum++;
}

void testNodeConstructors()
{
    // test the constructors
    Node *t = new Node(5, NULL, NULL, NULL);
    int value = t->getValue();
    Node *parent = t->getParent();
    Node *left = t->getLeftChild();
    Node *right = t->getRightChild();
    
    testEqualityInts(value, 5);
    testEquality(parent, NULL);
    testEquality(left, NULL);
    testEquality(right, NULL);
}

void testNodeSetLeftSetRight()
{
    // test the setLeft and setRight methods
    Node *t1 = new Node(1);
    Node *t2 = new Node(2);
    Node *t3 = new Node(3);
    t1->setLeftChild(t2);
    t1->setRightChild(t3);
    
    testEquality(t1->getLeftChild(), t2);
    testEquality(t1->getRightChild(), t3);
    testEquality(t2->getParent(), t1);
    testEquality(t3->getParent(), t1);
}

void testNodeSetParent()
{
    Node *t1 = new Node(1, NULL, NULL, NULL);
    Node *t2 = new Node(2, NULL, NULL, NULL);
    
    t2->setParent(t1);
    testEquality(t2->getParent(), t1);
}

void testNodeSetValue()
{
    Node *t1 = new Node(4);
    t1->setValue(5);
    testEqualityInts(t1->getValue(), 5);
}

void testNode()
{
    cout << "***** testing Node *****" << endl;
    testNodeConstructors();
    testNodeSetLeftSetRight();
    testNodeSetParent();
    testNodeSetValue();
    cout << "***** end testing Node *****" << endl;
}