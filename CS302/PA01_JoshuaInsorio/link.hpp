//
//  link.hpp
//  proj1
//
//  Created by Joshua Insorio on 2/16/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#ifndef link_hpp
#define link_hpp

#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T item;
    node<T>* next;
};

template <typename T>
class list
{
    node<T> * head, *tail;
public:
    list();
    list(const list<T>& other);
    ~list();
    
    void addnew(const T item);
    void deleteitem();
    void shownumber();
    void showall();
    bool checkempty();
    void clear();
    
};



#endif /* link_hpp */
