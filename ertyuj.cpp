#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a singly linked list
struct SNode {
    int data;
    struct SNode* next;
};

// Structure for a node in a doubly linked list
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function prototypes for singly linked list
void createSLL(struct SNode** head, int data);
void displaySLL(struct SNode* head);
void insertAtBeginningSLL(struct SNode** head, int data);
void insertAtEndSLL(struct SNode** head, int data);
void insertAtPositionSLL(struct SNode** head, int data, int position);
void deleteAtBeginningSLL(struct SNode** head);
void deleteAtEndSLL(struct SNode** head);
void deleteAtPositionSLL(struct SNode** head, int position);

// Function prototypes for doubly linked list
void createDLL(struct DNode** head, int data);
void displayDLL(struct DNode* head);
void insertAtBeginningDLL(struct DNode** head, int data);
void insertAtEndDLL(struct DNode** head, int data);
void insertAtPositionDLL(struct DNode** head, int data, int position);
void deleteAtBeginningDLL(struct DNode** head);
void deleteAtEndDLL(struct DNode** head);
void deleteAtPositionDLL(struct DNode** head, int position);

int main() {
    int choice, data, position;
    struct SNode* head_singly = NULL;
    struct DNode* head_doubly = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Singly Linked List Operations\n");
        printf("2. Doubly Linked List Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSingly Linked List\n");
                printf("1. Create List\n");
                printf("2. Display List\n");
                printf("3. Insert at Beginning\n");
                printf("4. Insert at End\n");
                printf("5. Insert at Position\n");
                printf("6. Delete from Beginning\n");
                printf("7. Delete from End\n");
                printf("8. Delete from Position\n");
                printf("9. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter data for the list: ");
                        scanf("%d", &data);
                        createSLL(&head_singly, data);
                        break;
                    case 2:
                        displaySLL(head_singly);
                        break;
                    case 3:
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        insertAtBeginningSLL(&head_singly, data);
                        break;
                    case 4:
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        insertAtEndSLL(&head_singly, data);
                        break;
                    case 5:
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        printf("Enter position (starting from 1): ");
                        scanf("%d", &position);
                        insertAtPositionSLL(&head_singly, data, position);
                        break;
                    case 6:
                        deleteAtBeginningSLL(&head_singly);
                        break;
                    case 7:
                        deleteAtEndSLL(&head_singly);
                        break;
                    case 8:
                        printf("Enter position to delete (starting from 1): ");
                        scanf("%d", &position);
                        deleteAtPositionSLL(&head_singly, position);
                        break;
                    case 9:
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 2:
                printf("\nDoubly Linked List\n");
                printf("1. Create List\n");
                printf("2. Display List\n");
                printf("3. Insert at Beginning\n");
