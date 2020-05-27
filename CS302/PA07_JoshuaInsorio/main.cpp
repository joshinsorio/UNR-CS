#include "map.hpp"

int main()
{

	map t;
	std::ofstream fp("TSP.txt"); 
	t.printSolution(fp);
	t.printAllPaths(fp);
	fp.close();
	std::cout << "All path variations were written to TSP.txt." << std::endl;
	return 0;
}
