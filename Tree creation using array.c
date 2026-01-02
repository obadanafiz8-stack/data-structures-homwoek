#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef struct {
    int data[MAX_TREE_SIZE];
    int size;
} ArrayTree;

void initTree(ArrayTree *tree) {
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        tree->data[i] = -1; // -1 indicates empty node
    }
    tree->size = 0;
}

void insertNode(ArrayTree *tree, int value) {
    if (tree->size >= MAX_TREE_SIZE) {
        printf("Tree is full\n");
        return;
    }
    
    tree->data[tree->size++] = value;
}

int getParentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}

int getLeftChildIndex(int parentIndex) {
    return 2 * parentIndex + 1;
}

int getRightChildIndex(int parentIndex) {
    return 2 * parentIndex + 2;
}

void printTree(ArrayTree *tree) {
    printf("Tree (array representation):\n");
    printf("Index: ");
    for (int i = 0; i < tree->size; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    
    printf("Value: ");
    for (int i = 0; i < tree->size; i++) {
        if (tree->data[i] != -1) {
            printf("%3d ", tree->data[i]);
        } else {
            printf("  - ");
        }
    }
    printf("\n");
}

void inorderTraversal(ArrayTree *tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) return;
    
    inorderTraversal(tree, getLeftChildIndex(index));
    printf("%d ", tree->data[index]);
    inorderTraversal(tree, getRightChildIndex(index));
}

void preorderTraversal(ArrayTree *tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) return;
    
    printf("%d ", tree->data[index]);
    preorderTraversal(tree, getLeftChildIndex(index));
    preorderTraversal(tree, getRightChildIndex(index));
}

void postorderTraversal(ArrayTree *tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) return;
    
    postorderTraversal(tree, getLeftChildIndex(index));
    postorderTraversal(tree, getRightChildIndex(index));
    printf("%d ", tree->data[index]);
}

// Example usage
void exampleArrayTree() {
    ArrayTree tree;
    initTree(&tree);
    
    // Creating a complete binary tree
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int numValues = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < numValues; i++) {
        insertNode(&tree, values[i]);
    }
    
    printTree(&tree);
    
    printf("\nTree Traversals:\n");
    printf("Inorder: ");
    inorderTraversal(&tree, 0);
    printf("\n");
    
    printf("Preorder: ");
    preorderTraversal(&tree, 0);
    printf("\n");
    
    printf("Postorder: ");
    postorderTraversal(&tree, 0);
    printf("\n");
    
    // Accessing parent and children
    printf("\nNode at index 2: %d\n", tree.data[2]);
    printf("Parent of index 2 (at index %d): %d\n", 
           getParentIndex(2), tree.data[getParentIndex(2)]);
    printf("Left child of index 2 (at index %d): %d\n", 
           getLeftChildIndex(2), tree.data[getLeftChildIndex(2)]);
    printf("Right child of index 2 (at index %d): %d\n", 
           getRightChildIndex(2), tree.data[getRightChildIndex(2)]);
}