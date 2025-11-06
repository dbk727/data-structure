#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;

void insertFirst() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    newnode->link = NULL;
    printf("\nEnter the value to insert at front: ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->link = head;
        head = newnode;
    }
    printf("\nElement inserted %d\n", newnode->data);
}

void insertLast() {
    struct node *temp = head, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    newnode->link = NULL;
    printf("\nEnter the element to insert at last: ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    printf("\nElement inserted successfully %d\n", newnode->data);
}

void insertLocation() {
    int key;
    struct node *temp = head, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    newnode->link = NULL;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter the key after which you want to add element: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key) {
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("\nValue not found\n");
    } else {
        printf("\nEnter the element to insert: ");
        scanf("%d", &newnode->data);
        newnode->link = temp->link;
        temp->link = newnode;
        printf("\nValue inserted successfully %d\n", newnode->data);
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    head = temp->link;
    printf("\nValue deleted %d\n", temp->data);
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (temp->link == NULL) {
        printf("\nValue %d deleted\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    printf("\nValue %d deleted\n", temp->data);
    prev->link = NULL;
    free(temp);
}

void deleteLocation() {
    int key;
    struct node *temp = head, *prev = NULL;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter the element to delete: ");
    scanf("%d", &key);
    if (temp->data == key) {
        head = temp->link;
        printf("\nValue %d deleted\n", temp->data);
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("\nValue not found\n");
        return;
    }
    prev->link = temp->link;
    printf("\nValue %d deleted\n", temp->data);
    free(temp);
}

void search() {
    struct node *temp = head;
    int pos = 1, found = 0, val;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter the value to search: ");
    scanf("%d", &val);
    while (temp != NULL) {
        if (temp->data == val) {
            printf("%d found at position %d\n", temp->data, pos);
            found = 1;
        }
        pos++;
        temp = temp->link;
    }
    if (!found) {
        printf("Value %d not found\n", val);
    }
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nElements in the list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("\nSINGLY LINKED LIST\n");
    do {
        printf("\n 1-> InsertFirst \n 2-> InsertLast \n 3-> Insert Location \n 4-> Delete first \n 5-> Delete last \n 6-> Delete location \n 7-> Search \n 8-> Display \n 9-> Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFirst(); break;
            case 2: insertLast(); break;
            case 3: insertLocation(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteLocation(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("\nExiting...\n"); exit(0);
            default: printf("\nInvalid choice\n");
        }
    } while (choice != 9);
    return 0;
}


