#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int** Adj;
} Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->Adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->Adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->Adj[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(Graph *graph, int src, int des) {
    graph->Adj[src][des] = 1;
    graph->Adj[des][src] = 1;
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->Adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
void DFSUtil(Graph *graph, int src, int *visited) {
    visited[src] = 1;
    printf("%d ", src);
    for (int i = 0; i < graph->V; i++) {
        if (graph->Adj[src][i] == 1 && visited[i] == 0) {
            DFSUtil(graph, i, visited);
        }
    }
}
void DFS(Graph *graph, int src) {
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    DFSUtil(graph, src, visited);
}

int main(void) {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    printGraph(graph);
    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);
    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(graph, start);
    printf("\n");

    return 0;
}
