#include<iostream>
#include<vector>
#include<queue>

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

    void BFS(int startvertex)
    {

        vector<bool> visited(vertices,false);
        queue<int> q;
        visited[startvertex]=true;
        q.push(startvertex);

        while(!q.empty())
        {

            int current_vertex = q.front();
            printf("visited %d \n", current_vertex);
            q.pop();

            for(int vertex:adjList[current_vertex])
            {
              if(!visited[vertex]){
                visited[vertex]=true;
                q.push(vertex);
              }

            }


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
    graph.BFS(0);



}

