#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int data;
    struct Graph* next;
} Graph;
Graph* createGraph(int value) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->data = value;
    graph->next = NULL;
    return graph;
}
void addEdge(Graph** adjList, int u, int v) {
    Graph* graph = createGraph(v);
    graph->next = adjList[u];
    adjList[u] = graph;
}
void printAdjList(Graph** adjList, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Graph* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[100][100];
    Graph* adjList[100] = {NULL};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) { 
            if (matrix[i][j] == 1) {
                addEdge(adjList, i, j);
            }
        }
    }
    printAdjList(adjList, n);
    return 0;
}

