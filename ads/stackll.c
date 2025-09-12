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
    }
    strcut Node* temp
}

