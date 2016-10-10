#include <string>
#include <iomanip>

#include "Graph.hpp"

Graph::Graph(int densityPercentage, int size, int minDistRange, int maxDistRange)
	: m_densityPercentage(densityPercentage)
	, m_minDistRange(minDistRange)
	, m_maxDistRange(maxDistRange)
	, m_graphMatrix(size, std::vector<int>(size, INFINITY_INT))
{
	GenerateGraph_();
}

Graph::Graph(const std::vector<std::vector<int>>& graph)
	: m_densityPercentage(0)
	, m_minDistRange(0)
	, m_maxDistRange(0)
	, m_graphMatrix(graph)
{
}

int Graph::GetNumberOfVertices() const
{
	return m_graphMatrix.size();
}

int Graph::GetNumberOfEdges() const
{
	int numOfEdges;

	for (auto & row : m_graphMatrix)
	{
		for (auto & edge: row)
		{
			if (edge != INFINITY_INT)
			{
				++numOfEdges;
			}
		}
	}

	return numOfEdges;
}

bool Graph::IsAdjacent(int x, int y) const
{
	if (x == y)
	{
		return false;
	}

	if (x >= m_graphMatrix.size())
	{
		return false;
	}

	if (y >= m_graphMatrix[x].size())
	{
		return false;
	}

	return (m_graphMatrix[x][y] != INFINITY_INT);
}

void Graph::GetNeighbours(int x, std::vector<int>& neighbours) const
{
	neighbours.clear();

	if (x >= m_graphMatrix.size())
	{
		return;
	}

	for (int i = 0 ; i < m_graphMatrix[x].size(); ++i)
	{
		if (m_graphMatrix[x][i] != INFINITY_INT &&
			x != i)
		{
			neighbours.push_back(i);
		}
	}

	return;
}

int Graph::GetEdgeValue(int x, int y) const
{
	if (x >= m_graphMatrix.size())
	{
		return INFINITY_INT;
	}

	if (y >= m_graphMatrix[x].size())
	{
		return false;
	}

	return m_graphMatrix[x][y];
}

bool Graph::SetEdgeValue(int x, int y, int value)
{
	if (x >= m_graphMatrix.size())
	{
		return false;
	}

	if (y >= m_graphMatrix[x].size())
	{
		return false;
	}

	m_graphMatrix[x][y] = value;

	return true;
}

void Graph::GenerateGraph_()
{
	srand (time(nullptr));

	for (int i = 0; i < m_graphMatrix.size(); ++i)
	{
		for (int j = 0; j < m_graphMatrix[i].size(); ++j)
		{
			if (i == j)
			{
				m_graphMatrix[i][j] = 0;
			}
			else
			{
				int randomPercentage = ((rand() / static_cast<float>(RAND_MAX)) * 100);

				if (randomPercentage < m_densityPercentage)
				{
					m_graphMatrix[i][j] = m_graphMatrix[j][i] = rand() % (m_maxDistRange - m_minDistRange + 1) + m_minDistRange;
				}
			}
		}
	}
}

std::ostream& operator<< (std::ostream &out, const Graph &graph)
{
	for (auto& row : graph.m_graphMatrix)
	{
		auto iter = row.begin();
		auto end = row.end();

		for (; iter != end; ++iter)
		{
			if (*iter == INFINITY_INT)
			{
				out << "  ∞";
			}
			else
			{
				out << std::setw(3) << std::right << *iter;
			}

			if ((iter + 1) != end)
			{
				out << ", ";
			}
		}

		out << std::endl;
	}

	return out;
}
