//
//  postfix.hpp
//  proj2
//
//  Created by Joshua Insorio on 2/18/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#ifndef postfix_h
#define postfix_h

//Header file
#include <iostream>
using namespace std;
template <class Type>
class stackType
{
    private:
        int maxStackSize;
        int stackTop;
        Type *list;
    
    public:
        void initializeStack();
        bool isFullStack()const;
        bool isEmptyStack()const;
        void push(const Type&);
        void pop();
        Type top()const;
        stackType(int = 20);
        ~stackType();
};

//Default constructor
template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
};

//Function to calculate if the stack size is equal to the max
template <class Type>
bool stackType<Type>::isFullStack() const
{
    if(stackTop >= maxStackSize)
    {
        return true;
    }
    else
    {
        return false;
    }
};

//Function to calculate if the stack is empty
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    if(stackTop == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

//Pushes the value passed into the function into the stack
template <class Type>
void stackType<Type>::push( const Type& newItem )
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
        //else statement if the the stack is full
        cout << "\n\t" << "Stack is already full";
};

//Function to pop the stack and removing a "layer"
template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;
    else
                //else statement if the the stack is already empty
        cout << "\n\t" << "Stack is already empty";
};

//Function to find the top of the stack
template <class Type>
Type stackType<Type>::top() const
{
    return list[stackTop - 1];
};

//Function to initialize the stacksize
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if ( stackSize <= 0 )
    {
        cout << "Invalid size";
    }
    else
        maxStackSize = stackSize;
    
    stackTop = 0;
    list = new Type[maxStackSize];
};

//Deconstructor
template <class Type>
stackType<Type>::~stackType()
{
    delete[] list;
};


#endif /* postfix_hpp */
