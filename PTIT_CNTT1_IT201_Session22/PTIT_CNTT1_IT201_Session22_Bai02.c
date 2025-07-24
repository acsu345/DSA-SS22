#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **Adj;
}Graph;
Graph *createGraph(int V) {
    Graph * graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->Adj = (int **)malloc(V * sizeof(int * ));
    for (int i = 0; i< V; i++) {
        graph->Adj[i] = (int *)malloc(V * sizeof(int *));
        for (int j = 0; j< V; j++ ) {
            graph->Adj[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(Graph * graph, int src, int des) {
    graph->Adj[src][des] = 1;
    graph->Adj[des][src] = 1;
}
void printGraph(Graph *graph) {
    for (int i = 0; i <graph->V; i++) {
        printf("%d: ", i);
        for (int j= 0; j< graph->V; j++) {
            if (graph->Adj[i][j] == 1) {
                printf("%d", j);
            }
        }
        printf("\n");
    }
}
int main(void) {
    int a;
    printf("Nhap vao so dinh: ");
    scanf("%d", &a);
    Graph *graph = createGraph(a);
    addEdge(graph,0,1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 1,3);
    addEdge(graph, 3,4);
    printGraph(graph);
    return 0;
}