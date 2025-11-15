#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int parent[MAX];

int findSet(int x) {
    if(parent[x]!=x) parent[x] = findSet(parent[x]);
    return parent[x];
}

void unionSet(int x, int y) {
    parent[findSet(y)] = findSet(x);
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void kruskal(struct Edge edges[], int n, int e) {
    for(int i=0;i<n;i++) parent[i] = i;

    qsort(edges, e, sizeof(struct Edge), compare);

    printf("\nKruskal's MST:\n");
    for(int i=0;i<e;i++){
        int u = edges[i].u;
        int v = edges[i].v;
        if(findSet(u) != findSet(v)){
            printf("%d -- %d  weight=%d\n", u, v, edges[i].w);
            unionSet(u,v);
        }
    }
}

int main() {
    int n, e;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for(int i=0;i<e;i++){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(edges, n, e);

    return 0;
}
