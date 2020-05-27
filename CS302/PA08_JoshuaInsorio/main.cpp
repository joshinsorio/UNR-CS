#include <iostream>
#include <vector>
#include <climits>

int minKey(int key[], bool mstSet[]);
void primMST(std::vector< std::vector<int> > Graph);
int printGraph(std::vector< std::vector<int> > Graph);
void printMST(int parent[], int n, std::vector< std::vector<int> > Graph);

int main()
{
    std::vector< std::vector<int> > Graph = 	
    {// 1  2  3  4  5  6
/*1*/ { 0, 2, 3, 0, 0, 0},
/*2*/ { 2, 0, 3, 0, 0, 0},
/*3*/ { 3, 3, 0, 5, 4, 0},
/*4*/ { 0, 0, 5, 0, 6, 1},
/*5*/ { 0, 0, 4, 6, 0, 2},
/*6*/ { 0, 0, 0, 1, 2, 0},
	};
    primMST(Graph);
    return 0;
}

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST 
int minKey(std::vector<int> weights, std::vector<bool> visited) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
    
    for (int v = 0; v < 5; v++) 
        if (visited[v] == false && weights[v] < min) 
            min = weights[v], min_index = v; 
    
    return min_index; 
} 

// A utility function to print the MST
void printMST(std::vector<int> path, int n, std::vector< std::vector<int> > Graph) 
{ 
    std::cout << "Edge \tWeight" << std::endl; 
    for(int i = 1; i < n; i++) 
    {
        std::cout << path[i] << "-" << i <<  "\t" << Graph[i][path[i]] << std::endl;
    }
} 

// Function to construct and print MST for a graph represented using adjacency matrix representation 
void primMST(std::vector< std::vector<int> > Graph) 
{ 
    std::vector<int> path(6, INT_MAX); 
    std::vector<int> weights(6,false);  
    std::vector<bool> visited(6);   
  
    for (int i = 0; i < 6; i++)
    {
        weights[i] = INT_MAX, visited[i] = false;
    } 
    weights[0] = 0;      
    path[0] = -1;
  
    for (int count = 0; count < 5; count++) 
    { 
        int u = minKey(weights, visited); 
        visited[u] = true; 
        for (int v = 0; v < 6; v++) 
        {
            if (Graph[u][v] && visited[v] == false && Graph[u][v] < weights[v]) 
                {
                    path[v] = u, weights[v] = Graph[u][v]; 
                }
        }
    } 
  
    // print the constructed MST 
    printMST(path, 6, Graph); 
} 
