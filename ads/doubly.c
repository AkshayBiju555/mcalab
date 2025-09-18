#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL;

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;

}
void insertatBeg(int val)
{
    struct Node* newNode=createNode(val);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;

    }

} 
void insertatEnd(int val)
{
    struct Node* newNode=createNode(val);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
void deletefromBeg()
{
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    if(head!=NULL)
    {
        head->prev=NULL;
        
    }
    printf("deleted item: %d " temp->data);
    free(temp);
}
void deletefromEnd()
{
     if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        free(head); 
        return;
    }
    struct Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    struct Node* todelete=temp->next;
    temp->next=NULL;
    free(todelete);


}
