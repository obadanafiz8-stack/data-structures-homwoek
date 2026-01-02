#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// TRAVERSAL
void traverseForward(Node* head) {
    printf("Forward traversal: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void traverseBackward(Node* tail) {
    printf("Backward traversal: ");
    Node* current = tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// INSERT BETWEEN NODES
void insertBetween(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    Node* newNode = createNode(data);
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
}

// DELETE NODE
void deleteNode(Node** head, Node** tail, Node* delNode) {
    if (*head == NULL || delNode == NULL) return;
    
    // If node to be deleted is head
    if (*head == delNode) {
        *head = delNode->next;
    }
    
    // If node to be deleted is tail
    if (*tail == delNode) {
        *tail = delNode->prev;
    }
    
    // Change next only if node to be deleted is NOT the last node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    // Change prev only if node to be deleted is NOT the first node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    free(delNode);
}

// Example usage function
void exampleDoubleLinkedList() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* tail = createNode(3);
    
    // Link nodes
    head->next = second;
    second->prev = head;
    second->next = tail;
    tail->prev = second;
    
    traverseForward(head);
    
    // Insert between second and tail
    insertBetween(second, 25);
    
    traverseForward(head);
    
    // Delete second node
    deleteNode(&head, &tail, second);
    
    traverseForward(head);
}