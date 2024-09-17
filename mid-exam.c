#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function prototypes
struct Node* createList(int data);
void displayList(struct Node *head);
struct Node* insertAtBeginning(struct Node** head_ref, int new_data);
struct Node* insertAtEnd(struct Node* head, int new_data);
struct Node* deleteNode(struct Node** head_ref, int key);
struct Node* search(struct Node* head, int key);
void sortList(struct Node** head_ref); // Merge Sort implementation
struct Node* mergeLists(struct Node* a, struct Node* b);

int main() {
    struct Node* head = NULL;

    // Create sample list
    head = createList(1);
    head->next = createList(2);
    head->next->next = createList(3);
    head->next->next->next = createList(4);

    printf("Original List: ");
    displayList(head);

    // Insertion (demonstrated at beginning and end)
    head = insertAtBeginning(&head, 0);
    head = insertAtEnd(head, 5);
    printf("List after insertion: ");
    displayList(head);

    // Deletion
    head = deleteNode(&head, 3);
    printf("List after deletion: ");
    displayList(head);

    // Searching
    struct Node* found = search(head, 2);
    if (found) {
        printf("Key %d found\n", found->data);
    } else {
        printf("Key not found\n");
    }

    // Sorting (using Merge Sort)
    sortList(&head);
    printf("List after sorting: ");
    displayList(head);

    // Merging (demonstrated with two example lists)
    struct Node* list1 = createList(10);
    list1->next = createList(20);
    list1->next->next = createList(30);

    struct Node* list2 = createList(5);
    list2->next = createList(15);
    list2->next->next = createList(25);

    struct Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}

// createList - Creates a new node with the given data
struct Node* createList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for node
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// displayList - Traverses and prints the list
void displayList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// insertAtBeginning - Inserts a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = createList(new_data);
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
    return *head_ref;
}

// insertAtEnd - Inserts a new node at the end of the list (optimized)
struct Node* insertAtEnd(struct Node* head, int new_data) {
    struct Node* newNode = createList(new_data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return head;
}

// deleteNode - Deletes a node with the given key (optimized)
struct Node* deleteNode(struct Node** head_ref, int key) {
    // Base Case
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node *
