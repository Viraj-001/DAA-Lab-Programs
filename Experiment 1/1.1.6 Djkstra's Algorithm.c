#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int distance[MAX], pred[MAX], visited[MAX];
    int i, j, count, mindistance, nextnode;

    for(i = 1; i <= n; i++){
        distance[i] = INFINITY;
        pred[i] = INFINITY;
        visited[i] = 0;
    }

    distance[startnode] = 0;

    for(count = 1; count <= n - 1; count++){
        mindistance = INFINITY;
        nextnode = -1;

        for(i = 1; i <= n; i++){
            if(distance[i] < mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i;
            }
        }

        if(nextnode == -1)
            break;

        visited[nextnode] = 1;

        for(i = 1; i <= n; i++){
} 
