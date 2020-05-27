//
//  main.cpp
//  proj4
//
//  Created by Joshua Insorio on 3/24/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#include <iostream>
#include <memory>
#include <random>
#include "BinarySearchTree.hpp"
#include "BinaryNode.hpp"
using namespace std;

int main()
{
    BinarySearchTree<int> theTree;
    int numbers[100];
    
    //initialization for random ints
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 200);
    
    //Generate and check the random numbers
    for(int i = 0; i < 100; i++)
    {
        int temp = 0;
        temp = dis(gen);
        //Checks to see if the number generated is unique, if not generate a new number
        for(int j = -1; j < i; j++)
        {
            if(numbers[j] == temp)
            {
                temp = dis(gen);
                j = -1;
            }
        }
        numbers[i] = temp;
    }
    
    //Places the uniquely generated numbers into the tree
    for(int i = 0; i < 100; i++)
    {
        theTree.add(numbers[i]);
    }
    
    //Calls for the 3 different recursion methods
    theTree.postorderTraverse();
    theTree.preorderTraverse();
    theTree.inorderTraverse();
    
    cout << endl << endl << "The height of the tree is : " << theTree.getHeight() << endl;
    
    return 0;
}
