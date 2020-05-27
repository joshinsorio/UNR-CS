//
//  Sorter.hpp
//  proj3
//
//  Created by Joshua Insorio on 3/11/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#ifndef Sorter_hpp
#define Sorter_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
class MergeSort
{
    private:
        T *arr;
        T currentSize;
        T maxSize;
        long long int swaps = 0;
        long long int comparisons = 0;
        void Merge(T *arr, T first, T mid, T last);
    
    public:
        void MergeSorter(const T size);
        void Sort(T *arr, T first, T last);
        void generateRandom();
        void show() const;
        T getSwaps() const;
        T getComparisons()const;
        T *getarr() const;
        T getsize() const;
    
};

template <typename T>
class BubbleSort
{
    private:
        T *arr;
        T currentSize;
        T maxSize;
        long long int swaps = 0;
        long long int comparisons = 0;
    
    
    public:
        void BubbleSorter(const T size);
        void swap(T *a, T *b);
        void Sort(T *arr);
        void generateRandom();
        void show() const;
        T getSwaps() const;
        T getComparisons()const;
        T *getarr() const;
        T getsize() const;
    
};


#endif /* Sorter_hpp */
