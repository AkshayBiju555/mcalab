#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Function to enqueue a node
void enqueue(int node) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = node;
}

// Function to dequeue a node
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int node = queue[front++];
    if (front > rear) front = rear = -1; // Reset queue
    return node;
}

// Function to check if queue is empty
int isEmpty() {
    return front == -1;
}

// BFS function
void BFS(int adjMatrix[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal starting from node %d: ", start);

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        // Visit all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] == 1 && visited[i]==0) {
                enqueue(i);
                visited[i] = 1;
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

    BFS(adjMatrix, n, start);

    return 0;
}
