#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;


void insertatBeg(int val)
{
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=val;
newNode->next=head;
head=newNode;
}
void insertatEnd(int val)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;

    }
    else{
    struct Node* t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=newNode;
}
}
void insertatMid(int val,int pos)
{
    
    if(pos==1)
    {
        insertatBeg(val);
    
    }
    else{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    struct Node* t=head;
    for(int i=1;i<pos-1 && t!=NULL;i++)
    {
        t=t->next;
    }
    if (t == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
    newNode->next=t->next;
    t->next=newNode;
}
}

void deletefromBeg()
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    struct Node* t=head;
    head=head->next;
    free(t);
    printf("element deleted succesfully");
}
void deletefromEnd()
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    struct Node* t=head;
    while(t->next->next!=NULL)
    {
        t=t->next;
    }
    free(t->next);
    t->next=NULL;
}

void deletefromMid(int pos)
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
    for(int i=1;i<pos-1 && t!=NULL;i++)
    {
        t=t->next;
    }
    if (t == NULL || t->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node* del=t->next;
    t->next=del->next;
    free(del);
    printf("element at %d deleted succesfully",pos);

}
void searchelement(int key)
{
int pos=1;
if(head==NULL)
{
printf("empty list");
return;
}
struct Node* t=head;
while(t!=NULL)
{
   if(t->data==key)
   {
    printf("element found at position %d",pos);
    return;

   }
   t=t->next;
   pos++;

}
printf("element not found");
}

void display()
{
    if(head==NULL)
{
printf("empty list");
return;
}
struct Node* t=head;
while(t!=NULL)
{
    printf("%d->",t->data);
    t=t->next;
}

}
int main(){
    int choice,pos,val,key;
    while(1){
        printf("\n1.insertatbeg \n 2.insertatEnd \n3.InsertatMid  \n.4deleteatBeg \n5.DeleteatEnd \n6.DeleteatMid \n7.Search \n8.display");
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
            printf("enter element to insert:");
            scanf("%d",&val);
            printf("enter the position:");
            scanf("%d",&pos);
            insertatMid(val,pos);
            break;

            case 4:
            printf("delete from beginning");
            deletefromBeg();
            break;

            case 5:
            printf("delete from end");
            deletefromEnd();
            break;

            case 6:
            printf("enter the position to delete:");
            scanf("%d",&pos);
            deletefromMid(pos);
            break;

            case 7:
            printf("enter key value to search:");
            scanf("%d",&key);
            searchelement(key);
            break;

            case 8:
            printf("the list elements are:");
            display();
            break;

            case 9:
            return 0;
            break;

            default:
            printf("invalid choice");
        

        }

    }
}