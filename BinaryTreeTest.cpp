//
//  BinaryTreeTest.cpp
//  Euler18
//
//  Created by M.A. de Vos on 22-08-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include "BinaryTreeTest.hpp"
#include "BinaryTree.hpp"

using namespace std;

int btTestNum = 1;

void btTestEquality(void *obj1, void *obj2)
{
    if(obj1 == obj2) cout << "Test " << btTestNum << ": passed" << endl;
    else cout << "Test " << btTestNum << ": failed" << endl;
    btTestNum++;
}

void btTestEqualityInts(int a, int b)
{
    if(a == b) cout << "Test " << btTestNum << ": passed" << endl;
    else cout << "Test " << btTestNum << ": failed" << endl;
    btTestNum++;
}

void testBinaryTreeSizeIsEmptyRoot()
{
    BinaryTree *bt = new BinaryTree();
    btTestEqualityInts(bt->getSize(), 0);
    btTestEqualityInts(bt->isEmpty(), 1);
    btTestEquality(bt->getRoot(), NULL);
}

void testBinaryTreeAdRootRootSizeIsEmpty()
{
    BinaryTree *bt = new BinaryTree();
    bt->addRoot(5);
    Node *root = bt->getRoot();
    btTestEqualityInts(root->getValue(), 5);
    btTestEqualityInts(bt->getSize(), 1);
    btTestEqualityInts(bt->isEmpty(), 0);
}

void testBinaryTreeHasLeftInsertLeftLeftChildIsLeft()
{
    BinaryTree *bt = new BinaryTree();
    bt->addRoot(1);
    bt->insertLeft(bt->getRoot(), 2);
    
    btTestEqualityInts(bt->getSize(), 2);
    bt->insertLeft(bt->getLeftChild(bt->getRoot()), 3);
    btTestEqualityInts(bt->hasLeftChild(bt->getRoot()), 1);
    btTestEqualityInts(bt->hasLeftChild(bt->getLeftChild(bt->getRoot())), 1);
    btTestEqualityInts(bt->isLeftChild(bt->getLeftChild(bt->getRoot())), 1);
}

void testBinaryTreeHasRightInsertRightRightChildIsRight()
{
    BinaryTree *bt = new BinaryTree();
    bt->addRoot(1);
    bt->insertRight(bt->getRoot(), 2);
    
    btTestEqualityInts(bt->getSize(), 2);
    bt->insertRight(bt->getRightChild(bt->getRoot()), 3);
    btTestEqualityInts(bt->hasRightChild(bt->getRoot()), 1);
    btTestEqualityInts(bt->hasRightChild(bt->getRightChild(bt->getRoot())), 1);
    btTestEqualityInts(bt->isRightChild(bt->getRightChild(bt->getRoot())), 1);
}

void testBinaryTreeHasParentParentIsInternalIsExternal()
{
    BinaryTree *bt = new BinaryTree();
    bt->addRoot(4);
    btTestEqualityInts(bt->hasParent(bt->getRoot()), 0);
    bt->insertLeft(bt->getRoot(), 5);
    btTestEqualityInts(bt->hasParent(bt->getLeftChild(bt->getRoot())), 1);
    btTestEqualityInts(bt->isInternal(bt->getRoot()), 1);
    btTestEqualityInts(bt->isInternal(bt->getLeftChild(bt->getRoot())), 0);
    btTestEqualityInts(bt->isExternal(bt->getRoot()), 0);
    btTestEqualityInts(bt->isExternal(bt->getLeftChild(bt->getRoot())), 1);
}

void testBinaryTreeReplaceElementsSwapElements()
{
    BinaryTree *bt = new BinaryTree();
    bt->addRoot(1);
    bt->insertLeft(bt->getRoot(), 2);
    bt->insertRight(bt->getRoot(), 3);
    bt->replaceElement(bt->getLeftChild(bt->getRoot()), 5);
    btTestEqualityInts(bt->getLeftChild(bt->getRoot())->getValue(), 5);
    bt->swapElements(bt->getLeftChild(bt->getRoot()), bt->getRightChild(bt->getRoot()));
    btTestEqualityInts(bt->getRightChild(bt->getRoot())->getValue(), 5);
}

void testBinaryTree()
{
    cout << "***** testing BinaryTree *****" << endl;
    testBinaryTreeSizeIsEmptyRoot();
    testBinaryTreeAdRootRootSizeIsEmpty();
    testBinaryTreeHasLeftInsertLeftLeftChildIsLeft();
    testBinaryTreeHasRightInsertRightRightChildIsRight();
    testBinaryTreeHasParentParentIsInternalIsExternal();
    testBinaryTreeReplaceElementsSwapElements();
    cout << "***** end testing Node *****" << endl;
}