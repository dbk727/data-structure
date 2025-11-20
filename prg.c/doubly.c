#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node {
    int data;
    struct node *link;
    struct node *rink;
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
    newnode->rink = NULL;
    printf("\nEnter the element to insert: ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
    } 
    else {
        newnode->rink = head;
        head->link=newnode;
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
     newnode->rink = NULL;
    printf("\nEnter the element to insert at last: ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->rink != NULL) {
            temp = temp->rink;
        }
        newnode->link=temp;
        temp->rink = newnode;
    }
    printf("\nElement inserted successfully %d\n", newnode->data);
}
void insertLocation() {
    int key;
    struct node *temp = head, *newnode,*nxt;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
   
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    
   else
   {
    printf("Enter the key to insert\n");
    scanf("%d",&key);
    
    while(temp!=NULL&&temp->data!=key)
    { temp=temp->rink;
    }
    if (temp == NULL) {
        printf("\nNo element found\n");
        return;
    }
    
    printf("\nEnter element insert: ");
    scanf("%d", &newnode->data);
  
    if (temp->rink== NULL) {
        newnode->link=temp;
        newnode->rink=NULL;
        temp->rink=newnode;
    }
     else {
        nxt=temp->rink;
        newnode->link = temp;
        newnode->rink=nxt;
        temp->rink = newnode;
        nxt->link=newnode;}
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
struct node *temp=head,*nxt;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
  printf("\n %d deleted\n", temp->data);
    if (temp->rink == NULL) {
   
        head = NULL;
    }
  else {
         nxt=temp->rink;
         head=nxt;
         nxt->link=NULL; 
    }
  
    free(temp);
}
 void deleteLocation(){
    int key;
    struct node *temp = head, *prev,*next;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter the element to delete: ");
    scanf("%d", &key);
    while(temp!=NULL&&temp->data != key) {
        temp=temp->rink;
        }
        
      if (temp==NULL){
        printf("\n No element found\n");
        return;
        }
      if(temp->link==NULL){
          head=temp->rink;
           if(head!=NULL)
           {  head->link->rink=NULL;
           }
    else if(temp->rink==NULL)
      { 
          temp->link->rink=NULL;
       }
       else
       {  
         prev=temp->link;
         next=temp->rink;
         prev->rink=next;
         next->link=prev;
         }
     printf("%d Deleted successfully\n",temp->data);
    free(temp);
}
}











void search() {
    struct node *temp = head;
    int pos = 0, found = 0, key;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter the value to search: ");
    scanf("%d", &key);
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d\n", temp->data, pos);
            found = 1;
        }
        pos++;
        temp = temp->rink;
    }
    if (!found) {
        printf("Value %d not found\n", key);
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
        temp = temp->rink;
    }

}

int main() {
    int choice;
    printf("\nDoubly LINKED LIST\n");
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
























