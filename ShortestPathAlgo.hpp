//
// ShortestPathAlgo.hpp - Contains class used compute shortest path between vertices
//

#pragma once

#include "Graph.hpp"

//
// ShortestPathAlgo - Implements Dijkstra's algorithm and prints the shortest path
//
class ShortestPathAlgo
{
public:
	//
	// Prints the shortest path between two vertices
	// If the end vertex is -1, it prints all shortest paths from the source vertex
	// It also prints the total distance of that path.
	//
	static void PrintShortestPath(
		const Graph& graph,
		int sourceVertex = 0,
		int endVertex = -1);
};

