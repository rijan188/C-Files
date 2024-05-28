#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height; // Used for AVL Trees
};

// Function prototypes for BST
struct Node* createBSTNode(int data);
struct Node* insertBST(struct Node* node, int data);
struct Node* minValueNodeBST(struct Node* node);
struct Node* deleteNodeBST(struct Node* root, int data);
void preOrderTraversalBST(struct Node* node);

// Function prototypes for AVL Tree (including BST functions)
int getHeight(struct Node* node);
int max(int a, int b);
int getBalance(struct Node* node);
struct Node* rightRotate(struct Node* y);
struct Node* leftRotate(struct Node* x);
struct Node* insertAVL(struct Node* node, int data);
void preOrderTraversalAVL(struct Node* node); // Reuse BST traversal

int main() {
    struct Node* rootBST = NULL;
    struct Node* rootAVL = NULL;

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary Search Tree (BST) Operations\n");
        printf("2. AVL Tree Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nBST Operations\n");
                printf("1. Insert\n");
                printf("2. Delete\n");
                printf("3. Preorder Traversal\n");
                printf("4. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        rootBST = insertBST(rootBST, data);
                        break;
                    case 2:
                        printf("Enter data to delete: ");
                        scanf("%d", &data);
                        rootBST = deleteNodeBST(rootBST, data);
                        break;
                    case 3:
                        printf("Preorder traversal: ");
                        preOrderTraversalBST(rootBST);
                        printf("\n");
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 2:
                printf("\nAVL Tree Operations\n");
                printf("1. Insert\n");
                printf("2. Preorder Traversal\n");
                printf("3. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        rootAVL = insertAVL(rootAVL, data);
                        break;
                    case 2:
                        printf("Preorder traversal: ");
                        preOrderTraversalAVL(rootAVL); // Reuse BST traversal
                        printf("\n");
                        break;
                    case 3:
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

// BST functions

struct Node* createBSTNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertBST(struct Node* node, int data) {
    if (node == NULL) {
        return createBSTNode(data);
    }

    if (data < node->data) {
        node->left = insertBST(node->left, data);
    } else if (data > node->data) {
        node->right = insertBST(node->right, data);
    }

    return node;
}

struct Node* minValueNodeBST(struct Node* node) {
    struct Node* current = node;

    // Find the leftmost node
    while (current->left != NULL) {
        current = current->
