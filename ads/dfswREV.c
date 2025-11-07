#include <stdio.h>
#define MAX 100

int top = -1;
int stack[MAX];

void push(int n) 
{
    if (top >= MAX - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = n;
}

int pop() 
{
    if (top < 0) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// Iterative DFS
void DFS(int adjMatrix[MAX][MAX], int n, int start, int reverse) 
{
    int visited[MAX] = {0};
    top = -1; // Reset stack
    push(start);
    visited[start] = 1;

    printf("DFS traversal starting from node %d (%s neighbors): ", start, reverse ? "reverse" : "normal");

    while (!isEmpty()) 
    {
        int node = pop();
        printf("%d ", node);

        if (reverse) 
        {
            for (int i = n - 1; i >= 0; i--) {  // Reverse neighbor order
                if (adjMatrix[node][i] == 1 && visited[i] == 0) 
                {
                    push(i);
                    visited[i] = 1;
                }
            }
        } 
        else 
        {
            for (int i = 0; i < n; i++) {      // Normal neighbor order
                if (adjMatrix[node][i] == 1 && visited[i] == 0) {
                    push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int adjMatrix[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMatrix[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    DFS(adjMatrix, n, start, 0); // Normal neighbor order
    DFS(adjMatrix, n, start, 1); // Reverse neighbor order

    return 0;
}
