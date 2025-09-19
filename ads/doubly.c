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

void insertatPos(int val,int pos)
{
    struct Node* newNode=createNode(val);
    if (pos < 1) 
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    if(pos==1)
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    } 
    struct Node* temp=head;
    int i=1;
    while(i<pos-1 &&  temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL)
    {
        temp->next->prev=newNode;
    }
    temp->next=newNode;



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
    printf("deleted item: %d ", temp->data);
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
        free(head); 
        head=NULL;
        
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
void deletefromPos(int pos)
{
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    if(pos<1)
    {
        printf("invalid position");
        return;
    }
    if (pos == 1)
    {
      struct Node* temp = head;   
      head = head->next;           
      if (head != NULL)
      {
        head->prev = NULL; 
      }      
      free(temp);                  
      return;
    }
    struct Node* temp=head;
    int i=1;
    while(i<pos-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    if(temp==NULL || temp->next==NULL)
    {
        printf("position out of bounds");
        return;
    }
    struct Node* del=temp->next;
    temp->next=del->next;
    if(del->next!=NULL)
    {
        del->next->prev=temp;
    }
    free(del);
}
void display()
{
    if(head==NULL)
    {
     printf(" Empty list \n");
     return;
    }
   struct Node* t=head;
   while(t!=NULL)
   {
     printf("%d<->",t->data);
     t=t->next;
   }
   printf("null");

}
int main(){
    int choice,pos,val,key;
    while(1)
    {
        printf("\n1.Insert at beginning \n2.Insert at End \n3.Insert at any position  \n4.Delete at Beginning \n5.Delete at End \n6.Delete at any position \n7.Display \n8.exit");
        printf("\n Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter element to insert at the beginning:");
            scanf("%d",&val);
            insertatBeg(val);
            break;
            
            case 2:
            printf("enter element to insert at end:");
            scanf("%d",&val);
            insertatEnd(val);
            break;

            case 3:
            printf(" Enter element to insert : ");
            scanf("%d",&val);
            printf(" Enter the Position : ");
            scanf("%d",&pos);
            insertatPos(val,pos);
            break;

            case 4:
            printf(" Delete from Beginning");
            deletefromBeg();
            break;

            case 5:
            printf(" Delete from End");
            deletefromEnd();
            break;

            case 6:
            printf(" Enter the position to delete : ");
            scanf("%d",&pos);
            deletefromPos(pos);
            break;

            case 7:
            printf("\nThe list elements are :  ");
            display();
            break;

            case 8:
            return 0;
            break;

            default:
            printf(" \n Invalid choice \n");
        }
    }
}
