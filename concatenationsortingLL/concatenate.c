#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

void reverseList(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    struct Node *temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int choice, val, n, i;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate Lists\n");
        printf("8. Display Concatenated List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements to insert: ");
            scanf("%d", &n);
            printf("Enter elements: ");
            for (i = 0; i < n; i++) {
                scanf("%d", &val);
                insertEnd(&list1, val);
            }
        }
        else if (choice == 2) {
            printf("Enter number of elements to insert: ");
            scanf("%d", &n);
            printf("Enter elements: ");
            for (i = 0; i < n; i++) {
                scanf("%d", &val);
                insertEnd(&list2, val);
            }
        }
        else if (choice == 3) {
            printf("List 1: ");
            display(list1);
        }
        else if (choice == 4) {
            printf("List 2: ");
            display(list2);
        }
        else if (choice == 5) {
            sortList(list1);
            printf("List 1 sorted.\n");
        }
        else if (choice == 6) {
            reverseList(&list1);
            printf("List 1 reversed.\n");
        }
        else if (choice == 7) {
            merged = concatenate(list1, list2);
            printf("Lists concatenated.\n");
        }
        else if (choice == 8) {
            printf("Concatenated List: ");
            display(merged);
        }
        else if (choice == 9) {
            printf("Exiting...\n");
            exit(0);
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
