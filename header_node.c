#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* header; // Header node
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize a linked list
struct LinkedList* initializeLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->header = createNode(0); // Header node with data 0
    return list;
}

// Insert a new node at the end of the linked list
void insertEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = list->header;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

// Display the linked list
void displayLinkedList(struct LinkedList* list) {
    struct Node* current = list->header->next; // Skip the header node
    
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    
    printf("NULL\n");
}
int main() {
    struct LinkedList* list = initializeLinkedList();
    
    insertEnd(list, 10);
    insertEnd(list, 20);
    insertEnd(list, 30);
    
    printf("Linked List: ");
    displayLinkedList(list);

    
    return 0;
}
