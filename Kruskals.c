#include <stdio.h>
#include <stdlib.h>

#define INF 999 // Represents a very large value (no direct connection)

// Function prototypes
int find(int parent[], int i);
int unionSet(int parent[], int u, int v);

int main() {
    int cost[10][10]; // Cost adjacency matrix
    int parent[10] = {0}; // Tracks the parent of each node
    int n, ne = 0; // Number of vertices and edges added to MST
    int i, j, u, v, min, mincost = 0;

    printf("***** KRUSKAL'S ALGORITHM FOR MINIMUM SPANNING TREE *****\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF; // No edge between i and j
            }
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (ne < n - 1) { // Continue until we have n-1 edges
        min = INF;

        // Find the smallest edge
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int uParent = find(parent, u);
        int vParent = find(parent, v);

        // If including this edge doesn't form a cycle
        if (unionSet(parent, uParent, vParent)) {
            printf("Edge (%d, %d) = %d\n", u, v, min);
            mincost += min;
            ne++;
        }

        cost[u][v] = cost[v][u] = INF; // Mark edge as used
    }

    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}

// Find the root of a node
int find(int parent[], int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

// Union of two sets
int unionSet(int parent[], int u, int v) {
    if (u != v) {
        parent[v] = u; // Make one root the parent of the other
        return 1;
    }
    return 0;
}
