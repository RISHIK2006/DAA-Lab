#include <iostream>
#include <climits>

using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}


void printSolution(int dist[], int V) {
    cout << "Vertex \tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t" << dist[i] << endl;
    }
}


void dijkstra(int adjMatrix[][5], int src, int V) {
    int dist[5];  
    bool sptSet[5]; 

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int V = 5; 

    int adjMatrix[5][5] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int src = 0;
    dijkstra(adjMatrix, src, V);

    return 0;
}



