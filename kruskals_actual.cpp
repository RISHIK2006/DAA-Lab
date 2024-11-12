#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

void selectionSortEdges(vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (edges[j].weight < edges[minIdx].weight) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(edges[i], edges[minIdx]);
        }
    }
}

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void KruskalMST(Graph* graph) {
    vector<Edge> result;
    int e = 0;
    int parent[graph->V];
    int rank[graph->V];

    for (int v = 0; v < graph->V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    selectionSortEdges(graph->edges);

    for (int i = 0; i < graph->E && e < graph->V - 1; i++) {
        int u = findParent(parent, graph->edges[i].src);
        int v = findParent(parent, graph->edges[i].dest);

        if (u != v) {
            result.push_back(graph->edges[i]);
            unionSets(parent, rank, u, v);
            e++;
        }
    }

    int totalWeight = 0;
    cout << "Edges in the MST:\n";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << "\n";
        totalWeight += result[i].weight;
    }
    cout << "Total cost of MST: " << totalWeight << "\n";
}

void printAdjacencyMatrix(Graph* graph) {
    int adjMatrix[graph->V][graph->V];
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < graph->E; i++) {
        adjMatrix[graph->edges[i].src][graph->edges[i].dest] = graph->edges[i].weight;
        adjMatrix[graph->edges[i].dest][graph->edges[i].src] = graph->edges[i].weight;
    }

    cout << "Adjacency Matrix:\n";
    cout << "  ";
    for (int i = 0; i < graph->V; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < graph->V; i++) {
        cout << i << " ";
        for (int j = 0; j < graph->V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V = 4;
    int E = 5;
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edges.push_back((Edge){0, 1, 8});
    graph->edges.push_back((Edge){0, 2, 6});
    graph->edges.push_back((Edge){0, 3, 5});
    graph->edges.push_back((Edge){1, 3, 7});
    graph->edges.push_back((Edge){2, 3, 4});

    cout << "Kruskal's Algorithm:\n";
    printAdjacencyMatrix(graph);
    KruskalMST(graph);

    delete graph;
    return 0;
}

