#include <stdio.h>
#include <limits.h>

#define MAX 100

void prim(int n, int graph[MAX][MAX], int start) {
    int visited[MAX] = {0};
    int parent[MAX];
    int minEdge[MAX];

    for(int i=0;i<n;i++){
        minEdge[i] = INT_MAX;
        visited[i] = 0;
    }

    minEdge[start] = 0;
    parent[start] = -1;

    for(int count=0; count<n; count++){
        int u = -1;
        for(int i=0;i<n;i++){
            if(!visited[i] && (u==-1 || minEdge[i]<minEdge[u])) u=i;
        }

        visited[u] = 1;

        for(int v=0; v<n; v++){
            if(graph[u][v] && !visited[v] && graph[u][v]<minEdge[v]){
                minEdge[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nPrim's MST:\n");
    for(int i=0;i<n;i++){
        if(parent[i]!=-1)
            printf("%d -- %d  weight=%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for(int i=0;i<e;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    prim(n, graph, start);

    return 0;
}
