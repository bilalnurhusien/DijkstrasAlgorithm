//
// Graph - class used to represent a graph
//

#pragma once

#include <limits>
#include <vector>
#include <iostream>

static const int INFINITY_INT = std::numeric_limits<int>::max();

class Graph
{
public:

	//
	// Description:
	//
	//		Graph constructor
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
	Graph(int densityPercentage, int size, int minDistRange = 1, int maxDistRange = 10);

	//
	// Description:
	//
	//		Graph constructor
	//
	// Parameters:
	//
	//		const std::vector<std::vector<int>>& graph - 2 dimensional matrix to initialize the graph
	//
	Graph(const std::vector<std::vector<int>>& graph);

	//
	// Description:
	//
	//	Get number of vertices
	//
	int GetNumberOfVertices() const;

	//
	// Description:
	//
	//		Get number of edges
	//
	int GetNumberOfEdges() const;

	//
	// Description:
	//
	//		Are the two vertices adjacent. Note vertex id is zero based
	//
	bool IsAdjacent(int x, int y) const;

	//
	// Description:
	//
	//		Get nieghbours of vertex
	//
	// Parameters:
	//
	//		int x - vertex
	//
	//		std::vector<int>& neighbours - Vector of ids that are neighbours
	//
	void GetNeighbours(int x, std::vector<int>& neighbours) const;

	//
	// Description:
	//
	//		Graph constructor
	//
	// Parameters:
	//
	//		const std::vector<std::vector<int>>& graph - 2D matrix to initialize the graph
	//
	int GetEdgeValue(int x, int y) const;

	//
	// Description:
	//
	//		Graph constructor
	//
	// Parameters:
	//
	//		int x - vertex 1
	//
	//		int y - vertex 2
	//
	//		std::vector<int>& neighbours - Vector of ids that are neighbours
	//
	bool SetEdgeValue(int x, int y, int value);

	//
	// Description:
	//
	//		Friend ostream function used to print graph
	//
	//
	friend std::ostream& operator<< (std::ostream &out, const Graph &graph);

private:

	//
	// Description:
	//
	//		Used to generate the graph
	//
	void GenerateGraph_();

	int                           m_densityPercentage;
	int                           m_minDistRange;
	int                           m_maxDistRange;
	std::vector<std::vector<int>> m_graphMatrix;

};
