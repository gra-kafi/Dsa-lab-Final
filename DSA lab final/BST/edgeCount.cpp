#include <stdio.h>
#include <stdlib.h>

class Graph
{
    int adjmat[100][100]; // Adjacency matrix
    int nVertices; // Number of vertices
    bool directed; // Indicates if the graph is directed

public:
    // Constructor to initialize the graph
    Graph(int n, bool dir)
    {
        nVertices = n;
        directed = dir;

        // Initialize the adjacency matrix with 0s
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                adjmat[i][j] = 0;
            }
        }
    }

    // Method to add an edge between two vertices
    void addEdge(int v, int u)
    {
        adjmat[v][u] = 1; // Set the edge from v to u
        if (!directed)
        {
            adjmat[u][v] = 1; // Set the edge from u to v if the graph is undirected
        }
    }

    // Method to print the adjacency matrix
    void print()
    {
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                printf("%d ", adjmat[i][j]); // Print each entry in the matrix
            }
            printf("\n");
        }
    }

    // Method to count the number of edges
    int countEdges()
    {
        int edgeCount = 0;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                if (adjmat[i][j] == 1)
                {
                    edgeCount++;
                }
            }
        }

        // If the graph is undirected, each edge is counted twice, so divide by 2
        if (!directed)
        {
            edgeCount /= 2;
        }

        return edgeCount;
    }
};

int main()
{
    Graph graph(5, false); // Create a graph with 5 vertices, undirected

    // Adding edges based on the graph in Figure 1
    graph.addEdge(0, 1); // 1 <-> 2
    graph.addEdge(0, 2); // 1 <-> 3
    graph.addEdge(0, 3); // 1 <-> 4
    graph.addEdge(0, 4); // 1 <-> 5
    graph.addEdge(1, 2); // 2 <-> 3
    graph.addEdge(1, 3); // 2 <-> 4
    graph.addEdge(1, 4); // 2 <-> 5
    graph.addEdge(2, 3); // 3 <-> 4
    graph.addEdge(2, 4); // 3 <-> 5
    graph.addEdge(3, 4); // 4 <-> 5

    // Print the adjacency matrix
    graph.print();

    // Count the number of edges
    int edgeCount = graph.countEdges();
    printf("Total number of edges: %d\n", edgeCount);

    return 0;
}
