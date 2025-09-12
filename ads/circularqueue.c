 #include <stdio.h>
 #include <conio.h>
 #define MAX 5
 int front=-1,rear=-1;
 int q[MAX];

 int full()
 {
    return((front==0 && rear==MAX-1) || (front==rear+1));
 }

 int empty()
 {
    return(front==-1);
 }

 void enqueue(int val)
 {
    if(full())
    {
        printf("\nqueue overflow");
        return;

    }
    if(front==-1)
    {
        front=0;

    }
    rear=(rear+1)%MAX;
    q[rear]=val;
   // printf("\n %d inserted", val);

 }

 void dequeue()
 {
    if(empty())
    {
        printf("\n queue undeflow");
        return;
    }
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%MAX;

    }

}
void display()
{
    if(empty())
    {
        printf("\n queue undeflow");
        return;
    }
    printf("\n queue elemets:");
    int i=front;
    while(1)
    {
        printf("<- %d:%d ->",i,q[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX;
    }
    printf("\n");

}

int main()
{
    int choice ,val;
    while(1)
    {
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit");
    printf("\n enter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    
    case 1:
    printf("\n enter the element to be inserted:");
    scanf("%d",&val);
    enqueue(val);
    break;

    case 2:
    dequeue();
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
