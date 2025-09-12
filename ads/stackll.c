#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top=NULL;


void push(int val)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL)
    {
        printf("stack overflow");
    }
        newNode->data=val;
        newNode->next=top;
        top=newNode;
}

void pop()
{
    if(top==NULL)
    {
        printf("stack underflow");
        return;
    }
    struct Node* temp=top;
    top=top->next;
    free(temp);
}

void display()
{
    if(top==NULL)
    {
        printf("\nStack Empty ");
        return;
    }
    struct Node* temp=top;
    printf("Stack [TOP]: ");
    while(temp!=NULL)
    {
        printf("%d ]",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}

 int main()
 {
    int choice,x;
    while(1){
    printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
    printf("\n enter choice:");
    scanf("%d",&choice);
    switch(choice){
    
    case 1:
    printf("\n enter the element to be inserted:");
    scanf("%d",&x);
    push(x);
    break;

    case 2:
    pop();
    
    break;
    
    case 3:
    display();
    break;

    case 4:
     return 0;
     break;

    default:
     printf("\ninvalid choice");
    }

    }
return 0;

 }
