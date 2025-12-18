#include <stdio.h>
#include <stdbool.h>

#define MAX 5

void DFS(int graf[MAX][MAX], bool visited[MAX], int dugum) {
    visited[dugum] = true;
    printf("%d ", dugum);
    
    for (int i = 0; i < MAX; i++) {
        if (graf[dugum][i] == 1 && !visited[i]) {
            DFS(graf, visited, i);
        }
    }
}

int main() {
  
    int graf[MAX][MAX] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1}, 
        {0, 0, 1, 1, 0}
    };

    bool visited[MAX] = {false};
    int clusterSayisi = 0;

    printf("Graph Cluster Analizi:\n");
    for (int i = 0; i < MAX; i++) {
        if (!visited[i]) {
            clusterSayisi++;
            printf("Cluster %d: ", clusterSayisi);
            DFS(graf, visited, i);
            printf("\n");
        }
    }

    return 0;
}
