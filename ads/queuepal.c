#include <stdio.h>
#include <conio.h>
#define MAX 5
int front=-1,rear=-1;
int q[MAX];
void enq(int x)
{
    if(rear==MAX-1)
    {
        printf(" \n queue overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        
        q[++rear]=x;
    }
 }
 void deq()
 {
    if(front==-1  || front>rear)
    {
        printf("\nqueue underflow");
    }
    else
    {
        int item=q[front++];
        printf("\ndeleted item %d",item);
    }
 }