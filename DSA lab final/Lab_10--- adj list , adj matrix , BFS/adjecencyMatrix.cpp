#include<stdio.h>
#include<stdlib.h>


class Graph
{

    int adjmat[100][100];
    int nVertices;
    bool directed;

public:
    Graph(int n, bool dir)
    {
        nVertices=n;
        directed=dir;

        for(int i=0; i<nVertices; i++)
        {
            for(int j=0; j<nVertices; j++)
            {
                adjmat[i][j]=0;
            }
        }


    }


    void addEdge(int v, int u)
    {
        adjmat[v][u]=1;
        if(!directed)
        {
            adjmat[u][v]=1;
        }

    }

    void print()
    {
        for(int i=0; i<nVertices; i++)
        {
            for(int j=0; j<nVertices; j++)
            {
                printf("%d ", adjmat[i][j]);
            }
            printf("\n");
        }


    }




};



int main()
{

    Graph graph(4, false);

    //graph.print();
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.print();


}
