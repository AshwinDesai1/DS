#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *l, *r;
};

// Iterative Insert Function
struct Node* Insert(struct Node* root, int ele) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *curr = root, *prev = NULL;

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return root;
    }

    newNode->data = ele;
    newNode->l = newNode->r = NULL;

    // If tree is empty, make new node the root
    if (root == NULL) {
        return newNode;
    }

    // Iteratively find the right place to insert
    while (curr != NULL) {
        prev = curr;
        if (ele < curr->data) {
            curr = curr->l;
        } else {
            curr = curr->r;
        }
    }

    // Insert the new node at the correct position
    if (ele < prev->data) {
        prev->l = newNode;
    } else {
        prev->r = newNode;
    }

    return root;
}

// Iterative Inorder Traversal (Left-Root-Right)
void inorder(struct Node* root) {
    struct Node* curr = root;
    struct Node* stack[100]; // Stack to simulate recursion
    int top = -1;

    while (curr != NULL || top != -1) {
        // Reach the leftmost node
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->l;
        }

        // Pop the top node from the stack and visit it
        curr = stack[top--];
        printf("%d ", curr->data);

        // Move to the right node
        curr = curr->r;
    }
}

// Function to find the minimum node in a given tree (for deletion)
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->l != NULL) {
        root = root->l;
    }
    return root;
}

// Iterative delete function
struct Node* deleteNode(struct Node* root, int key) {
    struct Node *curr = root, *prev = NULL;

    // Find the node to delete
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data) {
            curr = curr->l;
        } else {
            curr = curr->r;
        }
    }

    // Node to be deleted not found
    if (curr == NULL) {
        printf("Node with value %d not found.\n", key);
        return root;
    }

    // Case 1: Node to be deleted has no children (leaf node)
    if (curr->l == NULL && curr->r == NULL) {
        if (curr == root) {
            free(curr);
            return NULL;
        }
        if (prev->l == curr) {
            prev->l = NULL;
        } else {
            prev->r = NULL;
        }
        free(curr);
    }
    // Case 2: Node to be deleted has one child
    else if (curr->l == NULL || curr->r == NULL) {
        struct Node* child = (curr->l != NULL) ? curr->l : curr->r;

        if (curr == root) {
            root = child;
        } else if (prev->l == curr) {
            prev->l = child;
        } else {
            prev->r = child;
        }

        free(curr);
    }
    // Case 3: Node to be deleted has two children
    else {
        struct Node* minNode = findMin(curr->r); // Find the minimum node in the right subtree
        int minVal = minNode->data;
        root = deleteNode(root, minVal); // Delete the minimum node in the right subtree
        curr->data = minVal; // Replace the data of the node to be deleted with the minimum value
    }

    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int ele, choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Display Inorder\n");
        printf("3. Delete a Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &ele);
            root = Insert(root, ele);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter Element to Delete: ");
            scanf("%d", &ele);
            root = deleteNode(root, ele);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice.\n");
        }
    }

    return 0;
}
