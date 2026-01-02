#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// QUEUE for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// DFS Implementation (Recursive)
void DFSUtil(int graph[MAX_VERTICES][MAX_VERTICES], bool visited[], int v, int n) {
    visited[v] = true;
    printf("%d ", v);
    
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFSUtil(graph, visited, i, n);
        }
    }
}

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS starting from vertex %d: ", start);
    DFSUtil(graph, visited, start, n);
    printf("\n");
}

// BFS Implementation
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int n) {
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);
    
    visited[start] = true;
    enqueue(&q, start);
    
    printf("BFS starting from vertex %d: ", start);
    
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// Example usage
void exampleGraphTraversal() {
    int n = 5;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };
    
    DFS(graph, 0, n);
    BFS(graph, 0, n);
}