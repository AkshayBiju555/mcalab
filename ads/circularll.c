#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;


void insertatBeg(int val)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    
    newNode->next = head;
    head = newNode;
    last->next = head; 
}
void insertatEnd(int val)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;

    }
    else
    {
    struct Node* t=head;
    while(t->next!=head)
    {
        t=t->next;
    }
    t->next=newNode;
    newNode->next=head;
    }
}
void insertatPos(int val,int pos)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if(head==NULL)
    {
        
       if (pos == 1)
        {
            insertatBeg(val);
            return;
        }
        else
        {
            printf("Invalid position in empty list.\n");
            free(newNode);
        }
        return;
    }
    if(pos==1)
    {
        insertatBeg(val);
        return;
    
    }
    else
    {
    struct Node* temp=head;
    int i=1;
    while(i<pos-1 && temp->next!=head)
    {
        temp=temp->next;
        i++;

    }
    newNode->next=temp->next;
    temp->next=newNode;

}
} 

void deletefromBeg()
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    if(head->next==head)
    {
        free(head);
        head=NULL;
        
        return;
    }
    struct Node* last=head;
    while(last->next!=head)
    {
        last=last->next;

    }
    struct Node* n=head; 
    last->next=head->next;
    head=head->next;
    free(n);
}
void deletefromEnd()
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    if(head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }
    struct Node* last=head;
    while(last->next->next!=head)
    {
        last=last->next;
    }
    struct Node* del=last->next;
    last->next=head;
    free(del);
    printf("last element deleted");

}

void deletefromPos(int pos)
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    if(pos==1)
    {
        deletefromBeg();
        return;
    }
    struct Node* t=head;
    for(int i=1;i<pos-1 && t->next!=head;i++)
    {
        t=t->next;
    }
    if ( t->next == head)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node* del=t->next;
    t->next=del->next;
    free(del);
    printf(" Element at %d deleted Succesfully",pos);

}
/*void searchelement(int key)
{
int pos=1;
if(head==NULL)
{
printf(" Empty list");
return;
}
struct Node* t=head;
while(t!=NULL)
{
   if(t->data==key)
   {
    printf(" Element found at position : %d \n",pos);
    return;

   }
   t=t->next;
   pos++;

}
printf(" Element not found \n");
}*/

void display()
{
  if(head==NULL)
{
printf(" Empty list \n");
return;
}
struct Node* last=head;
do
{
    printf("%d->",last->data);
    last=last->next;
}while(last!=head);
printf("back to head\n");

}
int main(){
    int choice,pos,val,key;
    while(1){
        printf("\n1.Insert at beginning \n2.Insert at End \n3.Insert at any position   \n4.Delete at Beginning \n5.Delete at End  \n6.Delete at any position \n8.Display \n9.exit");
        printf("\n Enter choice:");
        scanf("%d",&choice);
        switch(choice){
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

            /*case 7:
            printf(" Enter key value to Search : ");
            scanf("%d",&key);
            searchelement(key);
            break;*/

            case 8:
            printf("\nThe list elements are :  ");
            display();
            break;

            case 9:
            return 0;
            break;

            default:
            printf(" \n Invalid choice \n");
        

        }

    }
}