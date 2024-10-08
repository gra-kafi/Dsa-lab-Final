#include<iostream>
#include<vector>

using namespace std;

class Graph
{

    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int n)
    {
        vertices=n;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);

    }

    void print()
    {

        for(int i=0; i<vertices; i++)
        {
            printf("%d",i);
            for(int vertex:adjList[i])
            {
                printf("--> %d", vertex);
            }
            printf("\n");

        }

    }

};
int main()
{
  Graph graph(4);

  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(0,3);
  graph.addEdge(1,3);
  graph.addEdge(2,3);
  graph.print();



}
