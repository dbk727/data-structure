#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;


void enqueue() {
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("\nNo space available (Memory allocation failed)\n");
        return;
    }

    newnode->link = NULL;
    printf("\nEnter the element to insert: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }

    printf("\n%d inserted successfully\n", newnode->data);
}


void dequeue() {
    struct node *temp = head;

    if (head == NULL) {
        printf("\nNo element to delete (Queue is empty)\n");
        return;
    }

    printf("\n%d is deleted\n", temp->data);
    head = temp->link;
    free(temp);
}


void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nElements in queue are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


void search() {
    struct node *temp = head;
    int key, pos = 1, found = 0;

    if (head == NULL) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("\n%d found at position %d\n", temp->data, pos);
            found = 1;
        }
        pos++;
        temp = temp->link;
    }

    if (!found) {
        printf("\nElement not found\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== QUEUE MENU =====\n");
        printf("1 -> Enqueue\n");
        printf("2 -> Dequeue\n");
        printf("3 -> Display\n");
        printf("4 -> Search\n");
        printf("5 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: printf("\nExiting program.\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

