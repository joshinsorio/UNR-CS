#include <vector>
#include <iostream>
using namespace std;

//swap function
template <class T>
void swap(vector<T>&vec , int i, int j)
{
    T a = vec[i];
    vec[i] = vec[j];
    vec[j] = a;
}

//parition function for the vector_resort function
template <class T>
T partition(vector<T>& vec, int low, int high)
{

    T pi = vec[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++)
    {
        if(vec[j] <= pi)
        {
            if(i != j)
            {
                i++;
                swap(vec, i, j);
            }
        }
    }
    swap(vec, i + 1, high);
    return (i+1);
}

//vecotr_resort function
template <class T>
void vector_resort(vector<T> & vec, int low, int high)
{
    if(low < high)
    {
        T pi = partition(vec, low, high);
        vector_resort(vec, low, pi - 1);
        vector_resort(vec, pi + 1, high);
    }
}

//vector_research function
template <class T>
int vector_research(vector<T>& vec, int low, int high, const int key)
{
    int mid = (low + high)/2;
    if(low > high)
    {
        return -1;
    }
    if(vec[mid] == key)
    {
        return mid;
    }
    else if(vec[low] == key)
    {
        return low;
    }
    else if(vec[high] == key)
    {
        return high;
    }
    if(vec[mid] > key)
    {
        return vector_research(vec, low, mid -1 , key);
    }
    return vector_research(vec, mid + 1, high, key);
}