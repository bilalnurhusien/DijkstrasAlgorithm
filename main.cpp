//
//	Homework 2 - Implement Dijkstra's Algorithm and compute shortest paths between vertices in a graph
//

#include <assert.h>
#include <iostream>
#include "Graph.hpp"
#include "ShortestPathAlgo.hpp"

//
// Test graph 1 used for unit testing
//
std::vector<std::vector<int>> TestGraph1	=	{{0, 1, 2, 4, 8, 16},
												 {1, 0, INFINITY_INT, 1, 1, 2},
												 {2, INFINITY_INT, 0, INFINITY_INT, 1, INFINITY_INT},
												 {4, 1, INFINITY_INT, 0, 4, 1},
												 {8, 1, 1, 4, 0, 1},
												 {16, 2, INFINITY_INT, 1, 1,0}};

//
// Test graph 2 used for unit testing
//
std::vector<std::vector<int>> TestGraph2	=	{{0, 100, 200, 50},
												 {INFINITY_INT, 0, 75, INFINITY_INT},
												 {INFINITY_INT, INFINITY_INT, 0, INFINITY_INT},
												 {INFINITY_INT, 45, 85, 0}};

//
// Node count used for assignment
//
const int TEST_NODE_COUNT = 50;

/** Main entry for program
  *
  */
int main()
{
	//
	// Create test graphs of node size 50
	// with densities 20% and 40% and min/max
	// distances 1 and 10

	Graph graph1(20, TEST_NODE_COUNT, 1, 10);
	Graph graph2(40, TEST_NODE_COUNT, 1, 10);
	
	//
	// Create more test graphs using a different constructor
	//
	Graph graph3(TestGraph1);
	Graph graph4(TestGraph2);

	//
	// Use some assert statements to make sure test graphs are initialized properly
	//
	assert(graph1.GetNumberOfVertices() == TEST_NODE_COUNT);

	assert(graph2.GetNumberOfVertices() == TEST_NODE_COUNT);


	std::vector<int> neighbours;

	graph3.GetNeighbours(4, neighbours);

	assert(neighbours.size() == 5);


	graph4.GetNeighbours(0, neighbours);

	assert(neighbours.size() == 3);


	graph4.GetNeighbours(3, neighbours);

	assert(neighbours.size() == 2);

	assert(graph4.IsAdjacent(1, 2));

	assert(graph4.GetNumberOfVertices() == 4);

	//
	// Print graphs and shortest path from source
	//

	std::cout << "Graph 1:" << std::endl << std::endl;

	std::cout << graph1 << std::endl;

	ShortestPathAlgo::PrintShortestPath(graph1);


	std::cout << "Graph 2:" << std::endl << std::endl;

	std::cout << graph2 << std::endl;

	ShortestPathAlgo::PrintShortestPath(graph2);


	std::cout << "Graph 3:" << std::endl << std::endl;

	std::cout << graph3 << std::endl;

	ShortestPathAlgo::PrintShortestPath(graph3);


	std::cout << "Graph 4:" << std::endl << std::endl;

	std::cout << graph4 << std::endl;

	ShortestPathAlgo::PrintShortestPath(graph4);

	return 0;
} // main
