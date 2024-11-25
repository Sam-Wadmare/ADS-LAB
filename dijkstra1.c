#include <stdio.h>
#define INF 999 // A large value to represent infinity

void dijkstra(int source, int cost[20][20], int visited[20], int d[20], int n);

int main() {
    int n, source, cost[20][20], visited[20], d[20];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no connection):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source, cost, visited, d, n);

    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (i != source) {
            printf("To node %d: %d\n", i, d[i]);
        }
    }

    return 0;
}

void dijkstra(int source, int cost[20][20], int visited[20], int d[20], int n) {
    int min, u;

    // Initialize distance and visited arrays
    for (int i = 0; i < n; i++) {
        d[i] = cost[source][i];
        visited[i] = 0;
    }

    visited[source] = 1; // Mark source as visited
    d[source] = 0; // Distance to itself is 0

    // Find shortest path for all nodes
    for (int count = 1; count < n; count++) {
        min = INF;
        u = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break; // If no unvisited node is reachable, stop

        visited[u] = 1; // Mark the node as visited

        // Update distances to neighboring nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[u][i] != INF && d[u] + cost[u][i] < d[i]) {
                d[i] = d[u] + cost[u][i];
            }
        }
    }
}
