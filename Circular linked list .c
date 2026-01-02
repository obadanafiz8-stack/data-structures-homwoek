#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

CNode* createCNode(int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// TRAVERSAL
void traverseCircular(CNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Circular list traversal: ");
    CNode* current = head;
    
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    
    printf("\n");
}

// INSERT BETWEEN NODES
void insertBetweenCircular(CNode* prevNode, int data) {
    if (prevNode == NULL) return;
    
    CNode* newNode = createCNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// DELETE NODE
void deleteNodeCircular(CNode** head, int key) {
    if (*head == NULL) return;
    
    CNode *current = *head, *prev = NULL;
    
    // If head node itself holds the key
    if (current->data == key) {
        // Find the last node
        CNode* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        
        // If this is the only node
        if (current->next == *head) {
            free(current);
            *head = NULL;
            return;
        }
        
        last->next = current->next;
        *head = current->next;
        free(current);
        return;
    }
    
    // Search for the key to be deleted
    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }
    
    // If key was not present
    if (current->data != key) {
        printf("Key not found\n");
        return;
    }
    
    // Unlink the node
    prev->next = current->next;
    free(current);
}

// Example usage function
void exampleCircularLinkedList() {
    CNode* head = createCNode(1);
    head->next = head; // Point to itself initially
    
    CNode* second = createCNode(2);
    second->next = head;
    head->next = second;
    
    CNode* third = createCNode(3);
    third->next = head;
    second->next = third;
    
    traverseCircular(head);
    
    // Insert between second and third
    insertBetweenCircular(second, 25);
    
    traverseCircular(head);
    
    // Delete node with value 2
    deleteNodeCircular(&head, 2);
    
    traverseCircular(head);
}