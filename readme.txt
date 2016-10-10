Date: October 9, 2016

Brief:

	This program was created for the C++ for C programmers Part 1 course on coursera.
	It uses Dijkstra's algorithm to compute the shortest path between two vertices.

Description:

	There are two main classes in this project:

	1. The Graph class is used to create and store a 2 dimensional graph using an
	adjacency matrix. The Graph class has two constructors. One constructor can be
	used to generate a undirectional graph, using a density and size parameter.
	The other Graphconstructor is used to initialize the graph directly using a 2
	dimensional vector.

	2. The ShortestPathAlgo class uses Dijkstra's algorithm to determine the shortest
	path between two vertices. It uses std::make_heap to create a min heap (priority queue)
	that is usedin Dijkstra's algorithm. The class also uses comparators to compare
	two vertices and determine the next shortest path. The ShortestPathAlgo has one
	static method that can be used without initialzing the class. The method is called
	PrintShortestPath() which prints the shortest path between every vertex and the
	source vertex. Alternatively,the method can also print the shortest path between two vertices.

	Finally, main.cpp contains the entry point of the program. It has several assert statements
	to test the classes. The main program outputs the graph contents and the shortest path from
	the source vertex.
