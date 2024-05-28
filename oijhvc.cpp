#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// Function prototypes for MST using Prim's algorithm
void createGraphMST(int graph[MAX_SIZE][MAX_SIZE], int vertices);
void primMST(int graph[MAX_SIZE][MAX_SIZE], int vertices);

// Function prototypes for shortest path using Dijkstra's algorithm
void createGraphDijkstra(int graph[MAX_SIZE][MAX_SIZE], int vertices);
void dijkstra(int graph[MAX_SIZE][MAX_SIZE], int vertices, int source);

int main() {
    int graphMST[MAX_SIZE][MAX_SIZE], graphDijkstra[MAX_SIZE][MAX_SIZE];
    int vertices, choice, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Get graph input for MST (assuming undirected graph)
    printf("Enter the adjacency matrix for MST (weights for edges):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graphMST[i][j]);
        }
    }

    // Get graph input for Dijkstra's algorithm (assuming weighted graph)
    printf("Enter the adjacency matrix for Dijkstra's algorithm (weights for edges):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graphDijkstra[i][j]);
            if (graphDijkstra[i][j] == 0) {
                graphDijkstra[i][j] = INT_MAX; // Represent no edge as infinity
            }
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Minimum Spanning Tree (MST) using Prim's Algorithm\n");
        printf("2. Shortest Path using Dijkstra's Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMinimum Spanning Tree:\n");
                primMST(graphMST, vertices);
                break;
            case 2:
                printf("\nShortest Path:\n");
                printf("Enter the source vertex: ");
                scanf("%d", &source);
                dijkstra(graphDijkstra, vertices, source);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

// Functions for MST using Prim's algorithm

void createGraphMST(int graph[MAX_SIZE][MAX_SIZE], int vertices) {
    // Assuming undirected graph, fill the upper triangular matrix for clarity
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = graph[j][i]; // Copy to upper triangle
        }
    }
}

void primMST(int graph[MAX_SIZE][MAX_SIZE], int vertices) {
    int parent[vertices]; // Array to store constructed MST
    int key[vertices];     // Key values used to pick minimum edge in cut
    bool mstSet[vertices]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have vertices equal to the number of vertices in the graph
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet, vertices);

        // Add the picked vertex to the MST Set
        mstSet[u
