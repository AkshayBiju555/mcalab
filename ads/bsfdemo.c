#include <stdio.h>
#include <conio.h>
#define MAX 100
int queue[MAX],front=-1,rear=-1




int main
{
    int n,start,adjmatrix[MAX][MAX];
    printf("enter the number of nodes:");
    scanf("%d",&n);
    prinf("enter the adjacency matrix:");
    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjmatrix[i][j]);
        }
    }
    printf("enter the starting node:");
    scanf("%d",&start);
    bfs(adjmatrix,n,start);
    return 0;


}