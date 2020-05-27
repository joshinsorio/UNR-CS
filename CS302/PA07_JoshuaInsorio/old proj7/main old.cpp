#include "map.hpp"

int main()
{
	int i = 0;
 
	// Take the input of the number of vertex and edges the graph have.
	struct Graph *G = CreateGraph(5);
	int edge[8][5];

	// Take the input of the adjacent vertex pairs of the given graph.
        edge[0][0] = 1; edge[0][1] = 2;
        InsertNode(G, edge[0][0], edge[0][1]);
        edge[1][0] = 1; edge[1][1] = 4;
        InsertNode(G, edge[1][0], edge[1][1]);
        edge[2][0] = 1; edge[2][1] = 5;
        InsertNode(G, edge[2][0], edge[2][1]);
        edge[3][0] = 2; edge[3][1] = 3;
        InsertNode(G, edge[3][0], edge[3][1]);
        edge[4][0] = 2; edge[4][1] = 5;
        InsertNode(G, edge[4][0], edge[4][1]);
        edge[5][0] = 3; edge[5][1] = 4;
        InsertNode(G, edge[5][0], edge[5][1]);
        edge[6][0] = 3; edge[6][1] = 5;
        InsertNode(G, edge[6][0], edge[6][1]);
        edge[7][0] = 4; edge[7][1] = 5;
        InsertNode(G, edge[7][0], edge[7][1]);

 
	// Print the incidence list representation of the graph.
	std::cout << std::endl << "The incidence list representation for the given graph: ";

	std::cout << std::endl << "\tV[Reno][1] -> {  ";
	while(G->vl[1].vlisthead != NULL)
	{
		std::cout << G->vl[1].vlisthead->data << "  ";
		G->vl[1].vlisthead = G->vl[1].vlisthead->link;
	}
	std::cout << "}";
    std::cout << std::endl;
    
	std::cout << std::endl << "\tV[San Francisco](2) -> {  ";
	while(G->vl[2].vlisthead != NULL)
	{
		std::cout << G->vl[2].vlisthead->data << "  ";
		G->vl[i+2].vlisthead = G->vl[2].vlisthead->link;
	}
	std::cout << "}";
    std::cout << std::endl;

	std::cout << std::endl << "\tV[Salt Lake City](3) -> {  ";
	while(G->vl[3].vlisthead != NULL)
	{
		std::cout << G->vl[3].vlisthead->data << "  ";
		G->vl[3].vlisthead = G->vl[3].vlisthead->link;
	}
	std::cout << "}";
    std::cout << std::endl;

	std::cout << std::endl << "\tV[Seattle](4) -> {  ";
	while(G->vl[4].vlisthead != NULL)
	{
		std::cout << G->vl[4].vlisthead->data << "  ";
		G->vl[4].vlisthead = G->vl[4].vlisthead->link;
	}
	std::cout << "}";
    std::cout << std::endl;

	std::cout << std::endl << "\tV[Las Vegas](5) -> {  ";
	while(G->vl[5].vlisthead != NULL)
	{
		std::cout << G->vl[5].vlisthead->data << "  ";
		G->vl[5].vlisthead = G->vl[5].vlisthead->link;
	}
	std::cout << "}";
    std::cout << std::endl << std::endl;
    

    return 0;
}