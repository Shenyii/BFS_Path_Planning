#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
	Map bfs_algorithm;
	bfs_algorithm.setObstacle(20, 20, 5, 40);
	bfs_algorithm.setObstacle(75, 20, 5, 40);
	bfs_algorithm.setObstacle(20, 60, 60, 20);
	bfs_algorithm.setStart(50, 50);
	bfs_algorithm.setDestination(50, 90);
	bfs_algorithm.searchThePath();
	bfs_algorithm.getPath();
	bfs_algorithm.display();
	return 0;
}