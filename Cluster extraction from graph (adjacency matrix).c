#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], bool visited[], int v, int n, int cluster[], int *clusterSize) {
    visited[v] = true;
    cluster[(*clusterSize)++] = v;
    
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(graph, visited, i, n, cluster, clusterSize);
        }
    }
}

void extractClusters(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    bool visited[MAX_VERTICES] = {false};
    int clusterNumber = 1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cluster[MAX_VERTICES];
            int clusterSize = 0;
            
            DFS(graph, visited, i, n, cluster, &clusterSize);
            
            printf("Cluster %d: ", clusterNumber++);
            for (int j = 0; j < clusterSize; j++) {
                printf("%d ", cluster[j]);
            }
            printf("\n");
        }
    }
}

// Example usage
void exampleClusterExtraction() {
    int n = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };
    
    extractClusters(graph, n);
}