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
	//		Graph& graph - graph
	//
	//		int sourceVertex - source vertex, default is 0
	//
	//		int endVertex - end vertex, default is -1 which means find the shortest path to every vertex on graph
	//
	static void PrintShortestPath(
		const Graph& graph,
		int sourceVertex = 0,
		int endVertex = -1);
};

