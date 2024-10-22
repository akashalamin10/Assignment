#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int key;
    char* data;
    struct Node* prev;
    struct Node* next;
};

// Structure for the doubly linked list
struct DoublyLinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* create_node(int key, char* data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// a) Check if the list is empty
int is_empty(struct DoublyLinkedList* list) {
    return list->head == NULL;
}

// b) Traverse forward
void traverse_forward(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current) {
        printf("Key: %d, Data: %s\n", current->key, current->data);
        current = current->next;
    }
}

// c) Traverse backward
void traverse_backward(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    if (current == NULL) {
        return; // List is empty
    }

    // Move to the last node
    while (current->next) {
        current = current->next;
    }

    // Traverse backward
    while (current) {
        printf("Key: %d, Data: %s\n", current->key, current->data);
        current = current->prev;
    }
}

// d) Insertion of a node at the last position
void insert_at_end(struct DoublyLinkedList* list, int key, char* data) {
    struct Node* new_node = create_node(key, data);
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    struct Node* last = list->head;
    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

// e) Insertion of a node after kth position
void insert_after_k(struct DoublyLinkedList* list, int k, int key, char* data) {
    struct Node* new_node = create_node(key, data);
    struct Node* current = list->head;
    int count = 0;

    // Traverse to the kth node
    while (current && count < k) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("The given position is out of bounds.\n");
        return;
    }

    new_node->next = current->next;
    if (current->next) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    new_node->prev = current;
}

// f) Deletion of the node at the last position
void delete_at_end(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    struct Node* last = list->head;
    while (last->next) {
        last = last->next;
    }

    last->prev->next = NULL;
    free(last);
}

// Main function for testing
int main() {
    struct DoublyLinkedList list;
    list.head = NULL;

    insert_at_end(&list, 1, "Node 1");
    insert_at_end(&list, 2, "Node 2");
    insert_at_end(&list, 3, "Node 3");

    printf("Traverse forward:\n");
    traverse_forward(&list);

    printf("\nTraverse backward:\n");
    traverse_backward(&list);

    printf("\nInsert after 1st position:\n");
    insert_after_k(&list, 1, 4, "Node 4");
    traverse_forward(&list);

    printf("\nDelete at end:\n");
    delete_at_end(&list);
    traverse_forward(&list);

    printf("\nIs the list empty? %s\n", is_empty(&list) ? "Yes" : "No");

    return 0;
}
