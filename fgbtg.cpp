#include <stdio.h>
#define MAX_SIZE 100

// Function prototypes
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int low, int high, int key);

// Hashing functions
int hashFunction(int key) {
    return key % MAX_SIZE; // Simple modulo hashing
}

void insertHash(int hashTable[], int data) {
    int index = hashFunction(data);

    // Handle collisions using linear probing
    while (hashTable[index] != -1) {
        index = (index + 1) % MAX_SIZE; // Move to next index
    }

    hashTable[index] = data;
}

void displayHashTable(int hashTable[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("%d at index %d\n", hashTable[i], i);
        } else {
            printf("-\n");
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, choice, data;

    int hashTable[MAX_SIZE]; // Initialize all hash table elements to -1 (empty)
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable[i] = -1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Searching\n");
        printf("2. Hashing\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSearching\n");
                printf("1. Linear Search\n");
                printf("2. Binary Search\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                printf("Enter key to search: ");
                scanf("%d", &key);

                switch (choice) {
                    case 1:
                        int index = linearSearch(arr, n, key);
                        if (index != -1) {
                            printf("Key found at index %d\n", index);
                        } else {
                            printf("Key not found\n");
                        }
                        break;
                    case 2:
                        // ... (Binary search implementation) // Requires sorted array
                        printf("Binary search is not implemented for unsorted arrays.\n");
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 2:
                printf("\nHashing\n");
                printf("1. Insert\n");
                printf("2. Display Hash Table\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        insertHash(hashTable, data);
                        break;
                    case 2:
                        displayHashTable(hashTable);
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

// Function implementations

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}

// Binary search implementation (omitted as it requires a sorted array)
// ... (implement binary search here)
