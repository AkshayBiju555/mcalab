#include <stdio.h>
#include <conio.h>
#define MAX 5
char st[MAX];
int top=-1;
void push(char s)
{
    if(top==MAX-1)
    {
        printf("stack overflow");
    }
    else
    {
        st[++top]=s;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {

         return st[top--];

    }
}
int main()
{
    char str[50],rev[50];
    int j=0;
    printf("enter the string: \n");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    printf("\n current string is: %s  ",str);
    for(int i=0;str[i]!='\0';i++)
    {
        rev[i]=pop();
        j++;
        
    }
    rev[j]='\0';
    printf("\n reversed string is : %s  ",rev);
}