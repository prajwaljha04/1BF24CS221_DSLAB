#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


void createList(int n) {
    int data, i;
    struct Node *newNode, *temp;

    if (n <= 0) {
        printf("Invalid size!\n");
        return;
    }

    head = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = temp;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }
}


void insertLeftOf(int value, int newData) {
    struct Node *newNode, *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list!\n", value);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;


    if (temp == head) {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    else {
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    printf("Inserted %d to the left of %d.\n", newData, value);
}

void deleteNode(int value) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list!\n", value);
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }

    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }

    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, value, newData;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert to the left of a node\n");
        printf("3. Delete node by value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many nodes do you want? ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter value to insert left of: ");
                scanf("%d", &value);
                printf("Enter new data: ");
                scanf("%d", &newData);
                insertLeftOf(value, newData);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                displayList();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

