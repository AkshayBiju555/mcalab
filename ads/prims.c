#include <stdio.h>

#define MAX 100

int main() {
    int n, start;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int totalCost = 0; // To store total weight of MST

    // Step 1: Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Step 2: Input adjacency matrix
    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Step 3: Input starting vertex
    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    visited[start] = 1; // Mark starting vertex as visited
    printf("Prim's MST edges:\n");

    // Step 4: Build MST
    for (int count = 0; count < n - 1; count++) {
        int u = -1, v = -1;
        int found = 0; // Flag to initialize min with first valid edge
        int min;

        // Find minimum edge connecting visited to unvisited vertex
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j]) {
                        if (!found || graph[i][j] < min) {
                            min = graph[i][j];
                            u = i;
                            v = j;
                            found = 1;
                        }
                    }
                }
            }
        }

        // Add edge to MST
        if (u != -1 && v != -1) {
            printf("%d -- %d  weight = %d\n", u, v, min);
            visited[v] = 1;
            totalCost += min; // Add edge weight to total cost
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
