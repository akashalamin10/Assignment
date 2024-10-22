#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specified position
struct Node* pushAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);
    
    // Insert at the head if position is 1
    if (position == 1) {
        newNode->next = head;
        return newNode;  // New head
    }

    // Traverse to the node before the desired position
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Insert the new node if temp is not NULL
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        // If position is greater than the list length, append to the end
        free(newNode);  // Free the node since we are not using it
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(value);
    }

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Create the linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(5);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(4);

    printf("Linked list before pushing 8: ");
    printList(head);

    int k;
    printf("Enter the position (k) to insert 8: ");
    scanf("%d", &k);  // Get user input for position k

    head = pushAtPosition(head, 8, k);  // Push 8 at position k

    printf("Linked list after pushing 8 at position %d: ", k);
    printList(head);

    return 0;
}
