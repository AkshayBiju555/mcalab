#include <stdio.h>
#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};   
    int indegree[MAX] = {0};     
    int queue[MAX];              
    int front = -1, rear = -1;   
    int topoOrder[MAX];          
    int count = 0;              
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (from to):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
    }

    // Step 1: Compute indegree of each vertex
    for (int v = 1; v <= n; v++) {
        indegree[v] = 0;
        for (int u = 1; u <= n; u++) {
            if (graph[u][v] == 1)
                indegree[v]++;
        }
    }

    // Step 2: Enqueue all vertices with indegree 0
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            if (front == -1) front = 0; // queue becomes non-empty
            queue[++rear] = i;
        }
    }

    // Step 3: Process queue (Kahn’s algorithm)
    while (front != -1 && front <= rear) {
        int u = queue[front++];          // dequeue
        topoOrder[count++] = u;          // add to topological order

        // If queue becomes empty after dequeue
        if (front > rear)
            front = rear = -1;

        // Decrease indegree of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    if (front == -1) front = 0;  // queue was empty
                    queue[++rear] = v;           // enqueue
                }
            }
        }
    }

    // Step 4: Check if topological sort is possible
    if (count != n) {
        printf("\nCycle detected! Topological sorting not possible.\n");
    } else {
        printf("\nTopological Order: ");
        for (int i = 0; i < count; i++)
            printf("%d ", topoOrder[i]);
        printf("\n");
    }

    return 0;
}
