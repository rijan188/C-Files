#include <stdio.h>
#define MAX_SIZE 100

// Structure for a node in a linked list (used for linear queue)
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void linear_enqueue(struct Node** front, struct Node** rear, int data);
int linear_dequeue(struct Node** front, struct Node** rear);
void display_linear_queue(struct Node* front);

void circular_enqueue(int queue[], int* front, int* rear, int data);
int circular_dequeue(int queue[], int* front, int* rear);
void display_circular_queue(int queue[], int* front, int* rear);

void priority_enqueue(int queue[], int* front, int* rear, int data, int priority);
int priority_dequeue(int queue[], int* front, int* rear);
void display_priority_queue(int queue[], int* front, int* rear);

int main() {
    struct Node* front_linear = NULL, *rear_linear = NULL;
    int queue_linear[MAX_SIZE];
    int front_circular = -1, rear_circular = -1;
    int queue_priority[MAX_SIZE];
    int front_priority = -1, rear_priority = -1;

    int choice, data, priority;

    while (1) {
        printf("\n1. Linear Queue Operations\n");
        printf("2. Circular Queue Operations\n");
        printf("3. Priority Queue Operations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // ... (Linear Queue operations)
                break;
            case 2:
                // ... (Circular Queue operations)
                break;
            case 3:
                printf("\nPriority Queue\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        printf("Enter priority (lower value = higher priority): ");
                        scanf("%d", &priority);
                        priority_enqueue(queue_priority, &front_priority, &rear_priority, data, priority);
                        break;
                    case 2:
                        // ... (Priority Queue dequeue)
                        break;
                    case 3:
                        display_priority_queue(queue_priority, &front_priority, &rear_priority);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

// Implementations for linear_enqueue, linear_dequeue, display_linear_queue, circular_enqueue, circular_dequeue, display_circular_queue (similar to previous code)

// Priority queue enqueue function
void priority_enqueue(int queue[], int* front, int* rear, int data, int priority) {
    // Check if queue is full
    if ((rear + 1) % MAX_SIZE == *front) {
        printf("Queue overflow\n");
        return;
    }

    // Handle first element or lower priority element
    if (*front == -1 || priority < queue[*front]) {
        // Enqueue at the front
        if (*front == -1) {
            *rear = 0;
        }
        queue[*front = (*front - 1 + MAX_SIZE) % MAX_SIZE] = data;
    } else {
        // Find the appropriate position based on priority (traverse from rear)
        int i = (*rear - 1 + MAX_SIZE) % MAX_SIZE;
        while (i != *front && priority >= queue[i]) {
            i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        }

        // Shift elements to make space for new element
        if (*rear == -1) {
            *front = i;
        }
