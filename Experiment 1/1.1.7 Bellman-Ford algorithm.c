#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j);
}

int main() {
    int V, E;
    if (scanf("%d", &V) != 1) return 0;
    if (scanf("%d", &E) != 1) return 0;

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    long long* dist = (long long*)malloc((V + 1) * sizeof(long long));
    int* parent = (int*)malloc((V + 1) * sizeof(int));

    for (int i = 1; i <= V; i++) {
        dist[i] = LLONG_MAX;
        parent[i] = -1;
