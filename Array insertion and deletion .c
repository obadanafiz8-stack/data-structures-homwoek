#include <stdio.h>

#define MAX_SIZE 100

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// INSERT AT POSITION
int insertAtPosition(int arr[], int *size, int position, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full\n");
        return 0;
    }
    
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = value;
    (*size)++;
    return 1;
}

// DELETE FROM POSITION
int deleteFromPosition(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty\n");
        return 0;
    }
    
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    return 1;
}

// Example usage
void exampleArrayOperations() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printArray(arr, size);
    
    // Insert at position 2
    insertAtPosition(arr, &size, 2, 99);
    printArray(arr, size);
    
    // Delete from position 3
    deleteFromPosition(arr, &size, 3);
    printArray(arr, size);
}