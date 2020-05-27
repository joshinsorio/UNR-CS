//
//  BinarySearchTree.hpp
//  proj4
//
//  Created by Joshua Insorio on 3/24/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include "BinaryNode.hpp"
#include <memory>
#include <iostream>
using namespace std;

template<class ItemType>
class BinarySearchTree
{
private:
    shared_ptr<BinaryNode<ItemType>> rootPtr;
    
protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    void inorderHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    void postorderHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    void preorderHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    int heightHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    
    
    // Recursively adds a new node to the tree in a left/right fashion to
    // keep the tree balanced.
    auto balancedAdd(shared_ptr<BinaryNode<ItemType>> subTreePtr, shared_ptr<BinaryNode<ItemType>> newNodePtr);
    
    // Places a given new node at its proper position in this binary
    // search tree.
    auto placeNode(shared_ptr<BinaryNode<ItemType>> subTreePtr, shared_ptr<BinaryNode<ItemType>> newNode);
    
    // Removes a given node from a tree while maintaining a binary search tree.
    auto removeNode(shared_ptr<BinaryNode<ItemType>> nodePtr);

    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    auto findNode(shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& isSuccessful) const;
    
public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    virtual ~BinarySearchTree();
    
    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& target);
    void clear();
    
    
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;
    
    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree

//Helper to traverse through the binary search tree and outputs into terminal, outputting the values inorder
template<class ItemType>
void BinarySearchTree<ItemType>::inorderHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(subTreePtr == nullptr)
        return;
    
    //recursion calls
    inorderHelper(subTreePtr->getLeftChildPtr());
    
    cout << subTreePtr->getItem() << " ";
    
    inorderHelper(subTreePtr->getRightChildPtr());
}

//Helper to traverse through the binary search tree and outputs into terminal, outputting the values in postorder
template<class ItemType>
void BinarySearchTree<ItemType>::postorderHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(subTreePtr == nullptr)
        return;
    
    //recursion calls
    postorderHelper(subTreePtr->getLeftChildPtr());
    
    postorderHelper(subTreePtr->getRightChildPtr());
    
    std::cout << subTreePtr->getItem() << " ";
}

//Helper to traverse through the binary search tree and outputs into terminal, outputting the values in preorder
template<class ItemType>
void BinarySearchTree<ItemType>::preorderHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(subTreePtr == nullptr)
        return;
    
    
    cout << subTreePtr->getItem() << " ";
    
    //recursion calls
    preorderHelper(subTreePtr->getLeftChildPtr());
    
    preorderHelper(subTreePtr->getRightChildPtr());
}

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(shared_ptr<BinaryNode<ItemType>> subTreePtr, shared_ptr<BinaryNode<ItemType>> newNode)
{
    if (subTreePtr == nullptr)
        return newNode;
    else
    {
        if (subTreePtr->getItem() > newNode->getItem())
        {
            subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr() , newNode));
        }
        else
        {
            subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr() , newNode));
        }  // end if
        
        return subTreePtr;
    }
}

//Function to add a newnode into the binarytree through the use of a smart pointer
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
    auto newNodePtr = make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template<class ItemType>
auto BinarySearchTree<ItemType>::findNode(shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& isSuccessful) const
{
    if(treePtr == nullptr)
        return nullptr;
    else if(treePtr->getItem() == target)
    {
        isSuccessful = true;
        return treePtr;
    }
    
    else if(treePtr->getItem() > target)
        return findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
    else
        return findNode(treePtr->getRightChildPtr(), target, isSuccessful);
}

//BinarySearchTree default ctor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
    
}  // end default constructor

//BinarySearchTree copy constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem):rootPtr(make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
    
}  // end constructor

//BinarySearchTree destructor
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
}  // end destructor

//getheight method to call the recursive heighthelper function to count height of the tree
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return this->heightHelper(rootPtr);
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

//Function(preorder) to traverse through the binary search tree and outputs into terminal
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
    cout << endl << "Preorder ---------------" << endl;
    this->preorderHelper(rootPtr);
}  // end preorderTraverse

//Function(inorder) to traverse through the binary search tree and outputs into terminal
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
    cout << endl << "Inorder ---------------" << endl;
    this->inorderHelper(rootPtr);
}  // end inorderTraverse

//Function(postorder) to traverse through the binary search tree and outputs into terminal
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
    cout << endl << "Postorder ---------------" << endl;
    this->postorderHelper(rootPtr);
}  // end postorderTraverse

//Helper function to recursively count the "layers" of the Binary tree
template<class ItemType>
int BinarySearchTree<ItemType>::heightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(subTreePtr == nullptr)
        return 1;
    
    return 1 + max(heightHelper(subTreePtr->getLeftChildPtr()), heightHelper(subTreePtr->getRightChildPtr()));
}


#endif /* BinarySearchTree_hpp */
