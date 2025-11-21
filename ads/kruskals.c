#include <stdio.h>

#define MAX 100

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

// Find with no path compression (simple)
int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

// Simple union
void Union(int a, int b) {
    parent[a] = b;
}

// Simple bubble sort for edges
void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge edges[MAX];

    printf("\nEnter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight
    sortEdges(edges, E);

    int mstWeight = 0;

    printf("\nMinimum Spanning Tree:\n");

    // Kruskal's algorithm
    for (int i = 0; i < E; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].w);
            mstWeight += edges[i].w;
            Union(a, b);
        }
    }

    printf("\nTotal cost of MST = %d\n", mstWeight);

    return 0;
}
