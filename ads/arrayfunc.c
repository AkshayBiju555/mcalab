#include<stdio.h>
#include<conio.h>
int main()
{
 int a[10];
 int size,i,num,del,position;
 printf("enter size of the array");
 scanf("%d",&size);
 printf("enter elements of array");
 for(i=0;i<size;i++)
 {
    scanf("%d",&a[i]);
 }
 printf("array elements-");
 for(i=0;i<size;i++)
 {
    printf("%d ",a[i]);
 }

printf("enter the number to find its index value \n ");
scanf("%d",&num);
 for(i=0;i<size;i++)
 {
    if(a[i]==num)
    {
        printf("element found at index %d ",i);
    }
    
 }
printf("enter the element position to delete \n");
scanf("%d ",&del);
for(i=del-1;i<size-1;i++)
{
    a[i]=a[i+1];
}
printf("array after deletion");
 for(i=0;i<size;i++)
 {
    printf("%d ",a[i]);
 }
 return 0;

}