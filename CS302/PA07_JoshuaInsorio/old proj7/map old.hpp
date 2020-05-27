#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <vector>
#include <string>


// A structure to represent a node in the adjacency list.
struct node
{
	int data;
	struct node *link;
};
 
// A structure to represent list of vertexes connected to the given vertex.
struct vertexlist
{
	struct node *vlisthead;
};
 
// A structure to maintain the graph vertexes and its connections to other vertexes.
struct Graph
{
	int v;
	struct vertexlist *vl; 
};
 
class map
{
    public:
        map();
        ~map();
    private:
        std::vector< std::vector<int> > weightedGraph =
        {	//        R  SF  SLC   SE   LV
            /*R*/	{ 0, 218, 518, 705, 439 },
            /*SF*/	{ 218, 0, 0, 807, 569 },
            /*SLC*/	{ 518, 0, 0, 840, 421 },
            /*SE*/	{ 705, 807, 840, 0, 1116 },
            /*LV*/	{ 439, 569, 421, 1116, 0 },
        }; 	
        std::string indexGraph[5] = {"Reno", "San Francisco", "Salt Lake City", "Seattle", "Las Vegas"};
        friend struct node;
        friend struct vertexlist;
        friend struct Graph;
            
};

map::map()
{}

map::~map()
{}


// A function to declare the graph according to the number of vertex.
struct Graph* CreateGraph(int n)
{
	int i;
	struct Graph *vlist = new Graph;
	vlist->v = n;
 
	// declare a list for n vertex.
	vlist->vl = new vertexlist[n+1];
 
	// Assign the head to NULL.
	for(i = 0; i < n+1; i++)
	{
		vlist->vl[i].vlisthead = NULL;
	}
 
	return vlist;
}
 
// A function to create a new data node.
struct node* NewNode(int value)
{
	struct node *newnode = new node;
	newnode->data = value;
	newnode->link = NULL;
 
	return newnode;
}
 
// A  function to add the edge into the undirected graph.
void InsertNode(Graph *G, int v1, int v2)
{
	node *newnode1 = NewNode(v1);
	node *newnode2 = NewNode(v2);
	// Since it is undirected graph, count each edge as two connection.
	// Connection 1, v2 to v1.
	if(G->vl[v2].vlisthead == NULL)
	{
		// If the head is null insert the node to the head.
		G->vl[v2].vlisthead = newnode1;
	}
	else
	{
		// Otherwise, add the node at the beginning.
		newnode1->link = G->vl[v2].vlisthead;
		G->vl[v2].vlisthead = newnode1;
	}
	// Connection 2, v1 to v2.
	if(G->vl[v1].vlisthead == NULL)
	{
		// If the head is null insert the node to the head.
		G->vl[v1].vlisthead = newnode2;
	}
	else
	{
		// Otherwise, add the node at the beginning.
		newnode2->link = G->vl[v1].vlisthead;
		G->vl[v1].vlisthead = newnode2;
	}
};





#endif