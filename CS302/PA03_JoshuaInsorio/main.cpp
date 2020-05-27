//
//  main.cpp
//  proj3
//
//  Created by Joshua Insorio on 3/9/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>
#include "Sorter.cpp"
using namespace std;

int main()
{
    char choice = '0';
    int size = 0;
    while(true)
    {
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Please pick an option:" << endl;
        cout << "1) Randomly Generate numbers into an array and sort via MergeSort" << endl;
        cout << "2) Randomly Generate numbers into an array and sort via BubbleSort" << endl;
        cout << "3) Terminate Program" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        MergeSort<int> list1;
        BubbleSort<int> list2;
        switch(choice)
        {
            //Case 1 which is strictly all the operations for MergeSort
            case '1':
            {
                cout << "Please define the size of the array(1000, 10000, 100000): ";
                cin >> size;
                list1.MergeSorter(size);
                list1.generateRandom();
                cout << "-----------------------------------------------" << endl;
                cout << "Unsorted Array: " << endl;
                list1.show();
                cout << endl;
                cout << "-----------------------------------------------" << endl;
                clock_t c_start = clock();
                list1.Sort(list1.getarr(), 0, list1.getsize()-1);
                clock_t c_end = clock();
                long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
                cout << "Sorted Array: " << endl;
                list1.show();
                cout << "MergeSort swaps: " << list1.getSwaps() << endl;
                cout << "MergeSort comparisons: " << list1.getComparisons() << endl;
                cout << "Time elapsed: " << time_elapsed_ms / 1000.0 << endl;
                break;
                
            }
                
            //Case 2 which is strictly all the operations for MergeSort
            case '2':
            {
                cout << "Please define the size of the array(1000, 10000, 100000): ";
                cin >> size;
                list2.BubbleSorter(size);
                list2.generateRandom();
                cout << "-----------------------------------------------" << endl;
                cout << "Unsorted Array: " << endl;
                list2.show();
                cout << endl;
                cout << "-----------------------------------------------" << endl;
                clock_t c_start = clock();
                list2.Sort(list2.getarr());
                clock_t c_end = clock();
                long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
                cout << "Sorted Array: " << endl;
                list2.show();
                cout << "BubbleSort swaps: " << list2.getSwaps() << endl;
                cout << "BubbleSort comparisons: " << list2.getComparisons() << endl;
                cout << "Time elapsed: " << time_elapsed_ms / 1000.0 << endl;
                break;
            }
            case '3':
                return 0;
                break;
                //Default case is for wrong entries and prompts user for another input.
                
            default:
                cout << "Invalid option, please try again" << endl;
                break;
        }
    }
    
    
    
    return 0;
}
