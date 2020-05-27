#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <climits>



class map {
	//public methods
public:

	map();

	void printSolution(std::ofstream& os);
	void printAllPaths(std::ofstream& os);
	int firstMin(int i);
	int secondMin(int i);
	void mapUtil();
	void mapRec(int curr_bound, int curr_weight, int level, std::vector<int> curr_path);


private:

	//Matrix for cities distances by miles, found on google maps
	std::vector<std::vector<int>> adj =
	{		/*R   SF  SLC   SE   LV*/
	/*R*/	{ 0, 218, 518, 705, 439 },
	/*SF*/	{ 218,  0,  0, 806, 570 },
	/*SLC*/	{ 518,  0,  0, 840, 421 },
	/*SE*/	{ 705, 806, 832, 0, 1116 },
	/*LV*/	{ 438, 569, 421, 1125, 0},
	};

	//indes of cities in string form
	std::vector<std::string> index = { "Reno", "San Francisco", "Salt Lake City", "Seattle", "Las Vegas" };

	//variables needed
	int final_weight = INT_MAX;
	std::vector<int> final_path;
	std::vector<bool> visited;
};

map::map()
{}

//Method to calculate the edge cost
int map::firstMin(int i)
{
	int min = INT_MAX;
	for (int j = 0; j < 5; j++)
		if (adj[i][j] < min && i != j)
			min = adj[i][j];

	return min;
}

//Method to calculate the second lowest edge cost at vertex i
int map::secondMin(int i)
{
	int first = INT_MAX, second = INT_MAX;

	for (int j = 0; j < 5; j++)
	{
		if (i == j)
			continue;

		if (adj[i][j] <= first)
		{
			second = first;
			first = adj[i][j];
		}
		else if (adj[i][j] <= second && adj[i][j] != first)
		{
			second = adj[i][j];
		}
	}

	return second;
}

//Recursive function to calculate shortest path and weight
void map::mapRec(int curr_bound, int curr_weight, int level, std::vector<int> curr_path)
{
	if (level == 5)
	{
		if (adj[curr_path[level - 1]][curr_path[0]] != 0)
		{
			int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];

			if (curr_res < final_weight)
			{
				final_weight = curr_res;
				final_path = curr_path;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (adj[curr_path[level - 1]][i] != 0 && visited[i] == false)
		{
			int temp = curr_bound;
			curr_weight += adj[curr_path[level - 1]][i];

			if (level == 1)
				curr_bound -= ((firstMin(curr_path[level - 1]) + firstMin(i)) / 2);
			else
				curr_bound -= ((secondMin(curr_path[level - 1]) + firstMin(i)) / 2);

			if (curr_bound + curr_weight < final_weight)
			{
				curr_path[level] = i;
				visited[i] = true;

				mapRec(curr_bound, curr_weight, level + 1, curr_path);
			}

			curr_weight -= adj[curr_path[level - 1]][i];
			curr_bound = temp;

			visited.assign(visited.size(), false);
			for (int j = 0; j <= level - 1; j++)
				visited[curr_path[j]] = true;

		}
	}
}

//Map function to call the recursive function
void map::mapUtil()
{
	std::vector<int> curr_path;
	int curr_bound = 0;

	curr_path.resize(5 + 1);
	visited.resize(curr_path.size());

	curr_path.assign(curr_path.size(), -1);
	visited.assign(curr_path.size(), false);

	for (int i = 0; i < 5; i++)
		curr_bound += (firstMin(i) + secondMin(i));

	curr_bound /= 2;

	visited[0] = true;
	curr_path[0] = 0;

	mapRec(curr_bound, 0, 1, curr_path);
}

//Pring the solution in the text document
void map::printSolution(std::ofstream &os)
{
	mapUtil();

	os << "Minimum cost: " << final_weight << std::endl << "Path by vertex number: ";
	for (unsigned int i = 0; i < 5; i++)
	{
		os << final_path.at(i);
		if (i != final_path.size() - 1)
			{
				os << " -> ";
			}
	}
	os << final_path.at(0) << std::endl;

	os << "Path by City name: ";
	for (unsigned int i = 0; i < 5; i++)
	{
		os << index[final_path.at(i)];
		os << " -> ";
	}
	os << index[0] << std::endl;
}

//printing all possible paths
void map::printAllPaths(std::ofstream& os)
{

	os << std::endl << "All Possible Paths - Assuming direct connections between all vertex" << std::endl;
	std::sort(index.begin() + 1, index.end());
	while (std::next_permutation(index.begin() + 1, index.end()))
	{

		for (int i = 0; i < 5; i++)
		{
			os << index[i];
			if (i != index.size() - 1)
			{
				os << " -> ";
			}
		}
		os << std::endl;
	}

	os << std::endl << "All Possible Paths - Assuming not all connections between all vertex" << std::endl;
	std::sort(index.begin() + 1, index.end());
	while (std::next_permutation(index.begin() + 1, index.end()))
	{

		for (int i = 0; i < 5; i++)
		{
			os << index[i];
			if (i != index.size() - 1)
			{
				os << " -> ";
			}
		}
		os << std::endl;
	} 

}

#endif