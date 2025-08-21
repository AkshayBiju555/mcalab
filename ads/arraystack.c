#include <stdio.h>
#include <conio.h>
#define MAX 5
int as[MAX],top=-1;

void push(int x)
{
    if(top==MAX-1)
    {
        printf("\nstack overflow");
    }
    else
    {
        as[++top]=x;

    }
}
int pop()
{
    if(top==-1)
    {
        printf("\n stack underflow");
    }
    else
    {
    int item=as[top--];
    printf("element deleted %d",item);
    }
}
void display()
{
    if(top==-1)
    {
        printf("\n stack empty");
    }
    else
    {
        printf("\n stack elements:");
        for(int i=0;i<=top;i++)
        {
            printf("%d  ",as[i]);
        }
    }
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