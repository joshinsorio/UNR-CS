//
//  Sorter.cpp
//  proj3
//
//  Created by Joshua Insorio on 3/11/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "Sorter.hpp"
using namespace std;


//MergeSorter constructor to construc a new array and initialize the sizes
template <typename T>
void MergeSort<T>::MergeSorter(const T size)
{
    maxSize = size;
    currentSize = size;
    arr = new T[maxSize];
}

//MergeSort function as provided in the slides
template <typename T>
void MergeSort<T>::Merge(T *arr, T first, T mid, T last)
{
    T tempArray[maxSize]; // Temporary array
                    // Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid+1; // Beginning of second subarray
    int last2 = last; // End of second subarray
                      // While both subarrays are not empty, copy the smaller item into the
                      // temporary array
    int index = first1; // next available location in tempArray
    while ((first1<=last1) && (first2 <=last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (arr[first1] <= arr[first2])
        {
            tempArray[index] = arr[first1];
            first1++;
            comparisons++;
        }
        
        else
        {
            tempArray[index] = arr[first2];
            first2++;
            comparisons++;
        } // end if
            index++;
    } // end while
    while(first1<=last1)
    {
            // at this point, tempArray[first..index-1] is in order
            tempArray[index] = arr[first1];
            first1++;
            index++;
            comparisons++;
    } // end while
                   // Finish off the second subarray, if necessary
            while (first2<=last2)
    {
            // at this point, tempArray[first..index-1] is in order
            tempArray[index] = arr[first2];
            first2++;
            index++;
            comparisons++;
    } // end for
            // Copy the result back into the original array
            for (index = first; index<=last; index++)
            {
            arr[index] = tempArray[index];
            comparisons++;
            }
}

//MergeSort recursive function from the lecture slides
template <typename T>
void MergeSort<T>::Sort(T *arr, T first, T last)
{
    if (first < last)
    {
        int mid = first + (last-first)/2;
        Sort(arr, first, mid);
        Sort(arr, mid+1, last);
        Merge(arr, first, mid, last);
    }
}

//MergeSort show function to display the entire array
template <typename T>
void MergeSort<T>::show() const
{
    if(arr[0] == '\0')
    {
        cout << "The array is empty";
    }
    else
    {
        for(int i = 0; i < maxSize; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
        
    }
}

//MergeSort get array function to return a pointer to the array
template <typename T>
T *MergeSort<T>::getarr() const
{
    return arr;
}

//MergeSort get size function to return the current size of the array
template <typename T>
T MergeSort<T>::getsize() const
{
    return currentSize;
}

//MergeSort generate random numbers function and to put input and output from a fstream file
template <typename T>
void MergeSort<T>::generateRandom()
{
    const int range_from  = 0;
    const int range_to    = 1000000;
    random_device                  rand_dev;
    mt19937                        generator(rand_dev());
    uniform_int_distribution<int>  distr(range_from, range_to);
    
    ofstream myfile;
    string number;
    //Naming the file depending on the size that was chosen
    switch(maxSize)
    {
        case 1000:
            number = to_string(1000);
            break;
        case 10000:
            number = to_string(10000);
            break;
        case 100000:
            number = to_string(10000);
            break;
    }
    myfile.open(number);
    //Generates the numbers and puts them into the file created
    for(int i = 0; i < maxSize; i++)
    {
        myfile << distr(generator) << endl;
    }
    myfile.close();
    ifstream file;
    file.open(number);
    //Reads all the numbers that was generated into the file and put it into the array
    for(int i = 0; i < maxSize; i++)
    {
        file >> arr[i];
    }
    file.close();
}

//MergeSort get swaps function to return the number of swaps
template <typename T>
T MergeSort<T>::getSwaps() const
{
    return swaps;
}


//MergeSort get comparisons function to return the number of comparisons
template <typename T>
T MergeSort<T>::getComparisons() const
{
    return comparisons;
}








//BubbleSort constructor to construc a new array and initialize the sizes
template <typename T>
void BubbleSort<T>::BubbleSorter(const T size)
{
    maxSize = size;
    arr = new T[maxSize];
    //arr = NULL;
}

//BubbleSort sort function to traverse and sort the array
template <typename T>
void BubbleSort<T>::Sort(T *arr)
{
    int i, j;
    for (i = 0; i < maxSize-1; i++)
        // Last i elements are already in place
        for (j = 0; j < maxSize-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swaps++;
                comparisons++;
            }
}

//BubbleSort show function to display the array
template <typename T>
void BubbleSort<T>::show() const
{
    if(arr[0] == '\0')
    {
        cout << "The array is empty";
    }
    
    else
    {
        for(int i = 0; i < maxSize; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
}

//BubbleSort get array function to return a pointer to the array
template <typename T>
T *BubbleSort<T>::getarr() const
{
    return arr;
}

//BubbleSort get size function to return the current size of the array
template <typename T>
T BubbleSort<T>::getsize() const
{
    return currentSize;
}

//BubbleSort swap function to swap two values that are passed in
template <typename T>
void BubbleSort<T>::swap(T *a, T *b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

//MergeSort generate random numbers function and to put input and output from a fstream file
template <typename T>
void BubbleSort<T>::generateRandom()
{
    const int range_from  = 0;
    const int range_to    = 1000000;
    random_device                  rand_dev;
    mt19937                        generator(rand_dev());
    uniform_int_distribution<int>  distr(range_from, range_to);
    
    ofstream myfile;
    string number;
    //Naming the file to the corresponding chosen size
    switch(maxSize)
    {
        case 1000:
            number = to_string(1000);
            break;
        case 10000:
            number = to_string(10000);
            break;
        case 100000:
            number = to_string(10000);
            break;
    }
    myfile.open(number);
    //Generating the numbers and putting them into the created file
    for(int i = 0; i < maxSize; i++)
    {
        myfile << distr(generator) << endl;
    }
    myfile.close();
    ifstream file;
    file.open(number);
    //Reading the numbers from the file into the array
    for(int i = 0; i < maxSize; i++)
    {
        file >> arr[i];
    }
    file.close();
}

//BubbleSort function to return the number of swaps that were counted
template <typename T>
T BubbleSort<T>::getSwaps() const
{
    return swaps;
}

//BubbleSort function to return the number of comparisons that were counted
template <typename T>
T BubbleSort<T>::getComparisons() const
{
    return comparisons;
}
