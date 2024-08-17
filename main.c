#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a list with one initial node
struct Node* createList(int data) {
    return createNode(data);
}

// Function to insert a node at the front
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(struct Node** head, struct Node* nextNode, int data) {
    if (*head == NULL || nextNode == NULL) {
        printf("The given next node cannot be NULL\n");
        return;
    }
    if (*head == nextNode) {
        insertFront(head, data);
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->next != nextNode) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found in the list\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = nextNode;
    temp->next = newNode;
}

// Function to insert a node at a specific position
void insertPosition(struct Node** head, int position, int data) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        insertFront(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node after a given node
void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("No node to delete after the given node\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

// Function to delete a node before a given node
void deleteBefore(struct Node** head, struct Node* nextNode) {
    if (*head == NULL || nextNode == NULL || *head == nextNode) {
        printf("No node to delete before the given node\n");
        return;
    }
    if ((*head)->next == nextNode) {
        deleteFront(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->next != nextNode) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found in the list\n");
        return;
    }
    prev->next = nextNode;
    free(temp);
}

// Function to delete a node from the front
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

// Function to delete a node at a specific position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position not found in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the list
void searchList(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

// Function to free the allocated memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    struct Node* node;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create the list\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Insert after a node\n");
        printf("5. Insert before a node\n");
        printf("6. Insert element at position\n");
        printf("7. Delete after a node\n");
        printf("8. Delete before a node\n");
        printf("9. Delete front element\n");
        printf("10. Delete end element\n");
        printf("11. Delete element at position\n");
        printf("12. Display the list\n");
        printf("13. Search the list\n");
        printf("14. Destroy the list\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the initial data for the list: ");
                scanf("%d", &data);
                head = createList(data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 4:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position after which to insert: ");
                scanf("%d", &position);
                node = head;
                for (int i = 0; node != NULL && i < position; i++) {
                    node = node->next;
                }
                insertAfter(node, data);
                break;
            case 5:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position before which to insert: ");
                scanf("%d", &position);
                node = head;
                for (int i = 0; node != NULL && i < position - 1; i++) {
                    node = node->next;
                }
                insertBefore(&head, node->next, data);
                break;
            case 6:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertPosition(&head, position, data);
                break;
            case 7:
                printf("Enter the position after which to delete: ");
                scanf("%d", &position);
                node = head;
                for (int i = 0; node != NULL && i < position; i++) {
                    node = node->next;
                }
                deleteAfter(node);
                break;
            case 8:
                printf("Enter the position before which to delete: ");
                scanf("%d", &position);
                node = head;
                for (int i = 0; node != NULL && i < position; i++) {
                    node = node->next;
                }
                deleteBefore(&head, node->next);
                break;
            case 9:
                deleteFront(&head);
                break;
            case 10:
                deleteEnd(&head);
                break;
            case 11:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 12:
                displayList(head);
                break;
            case 13:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                searchList(head, data);
                break;
            case 14:
                freeList(head);
                head = NULL;
                printf("List destroyed.\n");
                break;
            case 15:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
