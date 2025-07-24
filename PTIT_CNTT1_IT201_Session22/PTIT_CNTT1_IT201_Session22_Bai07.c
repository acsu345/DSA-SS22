#include <stdio.h>

int adj[100][100];
int visited[100];
int queue[100];
int front = 0, rear = 0;
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
void BFS(int start, int v) {
    for (int i = 0; i < v; i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        for (int i = 0; i < v; i++) {
            if (adj[u][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Nhap danh sach %d canh:\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }
    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);
    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start, v);
    printf("\n");

    return 0;
}
