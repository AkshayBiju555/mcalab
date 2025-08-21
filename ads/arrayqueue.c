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
 void display(){
    if(front==-1)
    {
        printf("\n underflow");
    }
    else
    {
        printf("\nqueue elements:");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }
 }

 int main()
 {
    int choice,x;
    while(1){
    printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit");
    printf("\n enter choice:");
    scanf("%d",&choice);
    switch(choice){
    
    case 1:
    printf("\n enter the element to be inserted:");
    scanf("%d",&x);
    enq(x);
    break;

    case 2:
    deq();
    break;
    
    case 3:
    display();
    break;

    case 4:
    return 0;
    break;

    default:
    printf("\n invalid choice");

    }
}    
return 0;
}