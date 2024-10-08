#include <iostream>
using namespace std;

int main() {
    int n;  // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int adjMatrix[100][100];  // Adjacency matrix
    int edgeCount = 0;

    // Input the adjacency matrix
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    // Counting the edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    cout << "Total number of edges: " << edgeCount << endl;
    return 0;
}
