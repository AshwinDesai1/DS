#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Global variables for the deque
int deque[SIZE];
int front = -1; // Front index of the deque
int rear = -1;  // Rear index of the deque

// Function to check if the deque is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

// Function to check if the deque is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element at the rear end of the deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0; // Wrap around
    } else {
        rear++;
    }
    deque[rear] = value;
}

// Function to insert an element at the front end of the deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1; // Wrap around
    } else {
        front--;
    }
    deque[front] = value;
}

// Function to delete an element from the front end of the deque
int deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -1;
    }
    int value = deque[front];
    if (front == rear) {
        // Only one element was in the deque
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
    return value;
}

// Function to delete an element from the rear end of the deque
int deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -1;
    }
    int value = deque[rear];
    if (front == rear) {
        // Only one element was in the deque
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1; // Wrap around
    } else {
        rear--;
    }
    return value;
}

// Function to modify an element at a given index
void modify(int index, int value) {
    if (isEmpty() || index < 0 || (front <= rear && (index < front || index > rear)) || (front > rear && (index < front && index > rear))) {
        printf("Invalid index\n");
        return;
    }
    deque[index] = value;
}

// Function to display all elements in the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    if (front <= rear) {
        for (; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    } else {
        for (; i < SIZE; i++) {
            printf("%d ", deque[i]);
        }
        i = 0;
        for (; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

// Main function with menu-driven interface
int main() {
    int choice, value, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Rear\n");
        printf("2. Insert at Front\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Modify an element\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 3:
                value = deleteFront();
                if (value != -1) {
                    printf("Deleted from front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear();
                if (value != -1) {
                    printf("Deleted from rear: %d\n", value);
                }
                break;
            case 5:
                printf("Enter index and value to modify: ");
                scanf("%d %d", &index, &value);
                modify(index, value);
                break;
            case 6:
                printf("Deque: ");
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
