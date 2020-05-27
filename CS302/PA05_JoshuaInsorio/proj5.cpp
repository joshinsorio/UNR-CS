#include <iostream>
#include <algorithm>
#include <random>
#include <numeric>
#include <fstream>

int returnmean(std::vector<int> v1);

int main()
{
    
    std::vector<int> v1;
    v1.reserve(100);


    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 200);
    
    //Generate and check the random numbers
    for(int i = 0; i < 100; i++)
    {
        int temp = 0;
        temp = dis(gen);
        v1.push_back(temp);
    }

    //make heap
    make_heap(v1.begin(), v1.end()); 

    //Output the heap into the terminal
    std::cout << std::endl << "Heap" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        std::cout << v1[i] << ", ";
    }
    std::cout << std:: endl;

    //Calculates the mean of the vector
    auto val =  std::accumulate(v1.begin(), v1.end(), 0) / 100;

    //adds a new value, the mean of the random values, into the heap
    v1.push_back(val);

    //Reorder the heap
    push_heap(v1.begin(), v1.end());

    //Output the heap into the terminal
    std::cout << std::endl << "After added mean" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        std::cout << v1[i] << ", ";
    }
    std::cout << std:: endl;

    // Displaying the maximum element of heap
    // using front()
    std::cout << std::endl << "The maximum element of heap after push is: ";
    std::cout << v1.front() << std::endl; 
    std::cout << "Deleting the maximum element of the heap and sort" << std::endl;

    // using pop_heap() to delete maximum element
    pop_heap(v1.begin(), v1.end());
    v1.pop_back(); 

    //Reorder the heap
    push_heap(v1.begin(), v1.end());

    //sorts heap in ascending order
    sort_heap(v1.begin(), v1.end());

    //Output the heap into the terminal
    std::cout << std::endl << "Sorted Heap" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        std::cout << v1[i] << ", ";
    }
    std::cout << std:: endl;



    return 0;
}
/*
int returnmean(std::vector<int> v1)
{
    int temp = 0;
    for(int i = 0; i < 100; i++)
    {
        temp += v1[i];
    }
    return temp/100;
}*/