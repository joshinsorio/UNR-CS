//
//  link.cpp
//  proj1
//
//  Created by Joshua Insorio on 2/16/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#include "link.hpp"
#include <iostream>
using namespace std;

//Default ctor for list class. This sets the head pointer to NULL upon creation.
template <typename T>
list<T>::list()
{
    head = NULL;
};

template <typename T>
list<T>::~list()
{
    //list dtor calls upon the clear function.
    clear();
};

template <typename T>
void list<T>::addnew(const T item)
{
    //Create a new node, setting the item to the item passed in the parameter. Then it sets next to the old head of the list before making the newnode the new head of the list. Also, because the tail pointer does not move it is initialized to the first head of the list.
    node<T>* newnode = new node<T>;
    newnode->item = item;
    newnode->next = head;
    head = newnode;
    if(newnode->next == NULL)
    {
        tail = head;
    }
};

template <typename T>
void list<T>::deleteitem()
{
    //Checks if the list is empty and does nothing if empty.
    if(checkempty() == true)
    {
        cout << "Can't delete, already empty!" << endl;
    }
    else
    {
        //If there are items in the list it deletes the current head after setting the new head to be the next node in line.
        node<T>* tempptr = new node<T>;
        tempptr = head;
        head = head->next;
        delete tempptr;
    }
    
};

template <typename T>
void list<T>::shownumber()
{
    //Goes through the node list until reaching NULL and increments after each node.
    int count = 0;
    node<T>* temp;
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << count << endl;
    delete temp;
};

template <typename T>
void list<T>::showall()
{
    //Similar to the count function, it goes through all the nodes until it reaches NULL and displays them in terminal.
    node<T>* temp;
    temp = head;
    if(temp == NULL)
    {
        cout << "list is empty" << endl;
    }
    while(temp != NULL)
    {
        cout << temp->item << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
};

template <typename T>
bool list<T>::checkempty()
{
    //Checks if there is a node that exists and returns a bool.
    node<T>* temp;
    temp = head;
    if(temp == NULL)
    {
        return true;
    }
    return false;
};

template <typename T>
void list<T>::clear()
{
    //Runs the deleteitem function until temp pointer reach NULL, which is the end of the list.
    node<T>* temp;
    temp = head;
    while(temp != NULL)
    {
        deleteitem();
    }
};
