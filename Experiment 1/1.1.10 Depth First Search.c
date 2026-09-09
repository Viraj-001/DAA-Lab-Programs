#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
	Node* newNode = createNode(v);
	if (adjList[u] == NULL || adjList[u]->vertex > v) {
		newNode->next = adjList[u];
		adjList[u] = newNode;
	} else {
		Node* curr = adjList[u];
		while (curr->next != NULL && curr->next->vertex < v) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
}
