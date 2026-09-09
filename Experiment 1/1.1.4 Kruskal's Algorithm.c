#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void kruskalMST(int **cost, int V) {
    int parent[V];

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0, minCost = 0, edgeNo = 0;

    while (edges < V - 1) {
        int min = 9999;
        int u = -1, v = -1;

        // Find the minimum weight edge
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Find roots of u and v
        int ru = u;
        while (parent[ru] != ru)
            ru = parent[ru];

        int rv = v;
        while (parent[rv] != rv)
            rv = parent[rv];
}
