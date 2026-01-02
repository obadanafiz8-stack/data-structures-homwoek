#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int arr[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

typedef struct {
    int arr[MAX_HEAP_SIZE];
    int size;
} MinHeap;

// MAX HEAP FUNCTIONS
void initMaxHeap(MaxHeap *heap) {
    heap->size = 0;
}

void maxHeapifyUp(MaxHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] < heap->arr[index]) {
            int temp = heap->arr[parent];
            heap->arr[parent] = heap->arr[index];
            heap->arr[index] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

void maxHeapifyDown(MaxHeap *heap, int index) {
    while (2 * index + 1 < heap->size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        
        if (left < heap->size && heap->arr[left] > heap->arr[largest])
            largest = left;
        if (right < heap->size && heap->arr[right] > heap->arr[largest])
            largest = right;
        
        if (largest != index) {
            int temp = heap->arr[index];
            heap->arr[index] = heap->arr[largest];
            heap->arr[largest] = temp;
            index = largest;
        } else {
            break;
        }
    }
}

void insertMaxHeap(MaxHeap *heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) return;
    
    heap->arr[heap->size] = value;
    maxHeapifyUp(heap, heap->size);
    heap->size++;
}

int extractMax(MaxHeap *heap) {
    if (heap->size == 0) return -1;
    
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapifyDown(heap, 0);
    
    return max;
}

// MIN HEAP FUNCTIONS
void initMinHeap(MinHeap *heap) {
    heap->size = 0;
}

void minHeapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] > heap->arr[index]) {
            int temp = heap->arr[parent];
            heap->arr[parent] = heap->arr[index];
            heap->arr[index] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

void minHeapifyDown(MinHeap *heap, int index) {
    while (2 * index + 1 < heap->size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        
        if (left < heap->size && heap->arr[left] < heap->arr[smallest])
            smallest = left;
        if (right < heap->size && heap->arr[right] < heap->arr[smallest])
            smallest = right;
        
        if (smallest != index) {
            int temp = heap->arr[index];
            heap->arr[index] = heap->arr[smallest];
            heap->arr[smallest] = temp;
            index = smallest;
        } else {
            break;
        }
    }
}

void insertMinHeap(MinHeap *heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) return;
    
    heap->arr[heap->size] = value;
    minHeapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(MinHeap *heap) {
    if (heap->size == 0) return -1;
    
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapifyDown(heap, 0);
    
    return min;
}

// Example usage functions
void printMaxHeap(MaxHeap *heap) {
    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void printMinHeap(MinHeap *heap) {
    printf("Min Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}