#include<stdio.h>
#include<stdlib.h>

struct node {
 int data;
 struct node *link;
};
 struct node *top=NULL;
 
 void push()
 { 
   struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    if (newnode==NULL){
     printf("\n No space\n");
     return;
     }
     newnode->link=NULL;
     
     printf("\nEnter the element to insert\n");
     scanf("%d",&newnode->data);
     
     if(top==NULL){
      top=newnode;
      }
     else { 
     newnode->link=top;
     top=newnode;
     }
     printf("\n %d Inserted successfully",newnode->data);
     }
void pop()
{
 struct node *temp=top;
 
 if(top==NULL){
	printf("\n Stack underflow!");
	return;
	}
	printf("\n %d popped from stack",temp->data);
	top=temp->link;
	free(temp);
}
void peek()
{
	struct node *temp=top;
	
	if(top==NULL)
	{
		printf("\n Stack is empty!");
		return;
	}
	printf("\n Top element is %d",temp->data);
}
void display()
{
 struct node *temp=top;
 if(top==NULL){
		printf("\n Stack is empty!");
		return;
	}
	printf("\n Stack element are: \n");
   while(temp!=NULL){
   
	{
		printf("%d \n",temp->data);
		temp=temp->link;
	}
}
}
void search()
{ 
struct node *temp=top;
int key,found=0;

if(top==NULL){
 printf("\n Stack underflow\n");
 return;
 }
 printf("\nEnter the element to search\n");
 scanf("%d",&key);
  while(temp!=NULL){
   if(temp->data=key)
   {
    printf("\n %d Element founded \n",temp->data);
    found+1;
    }
    temp=temp->link;
    }
    }
void main() 
{
	int choice;
	
	do{
	printf("\n   Stack   \n");
	printf("\n1->push()\n2->pop()\n3->peek()\n4->display()\n5->search()\n6->Exit");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:push();
			break;
			case 2: pop();
			break;
			case 3: peek();
			break;
			case 4: display();
			break;
			case 5: search();
			break;
			case 6: printf("\n Exit\n");
			break;
			default: printf("\n Invalid choice!");
		}
	}while(choice!=6);
}

