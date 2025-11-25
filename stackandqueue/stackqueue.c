#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to Stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped %d from Stack\n", temp->data);
    free(temp);
}

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d to Queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    printf("Dequeued %d from Queue\n", temp->data);
    free(temp);
}

void displayStack() {
    struct Node* temp = top;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayQueue() {
    struct Node* temp = front;
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, mode;

    while (1) {
        printf("Choose mode: 1 for Stack, 2 for Queue: ");
        scanf("%d", &mode);
        printf("\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            if (mode == 1)
                push(value);
            else if (mode == 2)
                enqueue(value);
            else
                printf("Invalid mode\n");
        }
        else if (choice == 2) {
            if (mode == 1)
                pop();
            else if (mode == 2)
                dequeue();
            else
                printf("Invalid mode\n");
        }
        else if (choice == 3) {
            if (mode == 1)
                displayStack();
            else if (mode == 2)
                displayQueue();
            else
                printf("Invalid mode\n");
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            exit(0);
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

