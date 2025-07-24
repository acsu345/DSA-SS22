#include <stdio.h>

int main() {
    int n, v;
    int adj[100][100] = {0};
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
        adj[w][u] = 1;
    }
    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (adj[k][i] == 1) {
            count++;
        }
    }
    printf("So dinh ke voi %d la: %d\n", k, count);
    return 0;
}
