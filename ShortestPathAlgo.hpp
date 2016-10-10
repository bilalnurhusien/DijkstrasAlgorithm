//
// ShortestPathAlgo.hpp - Contains class used to compute the shortest path between vertices
//

#pragma once

#include "Graph.hpp"

//
// ShortestPathAlgo - Implements Dijkstra's algorithm and prints the shortest path between vertices
//
class ShortestPathAlgo
{
public:

	//
	// Description:
	//
	//		Prints the shortest path between the source and end vertices
	//		If the end vertex is -1, it prints all shortest paths from the source vertex
	//		It also prints the total distance of the shortest path.
	//
	// Parameters:
	//
	//		int densityPercentage - Density of the graph
	//
	//		int size - Size of the graph (size x size)
	//
	//		int minDistRange - Minimum distance for an edge that exists
	//
	//		int maxDistRange - Maximum distace for an edge that exists
	//
	//
	static void PrintShortestPath(
		const Graph& graph,
		int sourceVertex = 0,
		int endVertex = -1);
};

