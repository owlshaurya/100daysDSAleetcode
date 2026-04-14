#include <stdlib.h>

// Find with path compression
int find(int parent[], int x) {
    if(parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union
void unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if(px != py)
        parent[px] = py;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {

    int n = edgesSize;

    int parent[n + 1];

    // initialize
    for(int i = 1; i <= n; i++)
        parent[i] = i;

    int* result = (int*)malloc(2 * sizeof(int));

    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        // if same parent → cycle
        if(pu == pv) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(parent, u, v);
        }
    }

    *returnSize = 2;
    return result;
}