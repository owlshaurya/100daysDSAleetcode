#include <stdlib.h>

#define MAX 100005

// adjacency list node
struct Node {
    int val;
    struct Node* next;
};

struct Node* adj[MAX];

int tin[MAX], low[MAX], visited[MAX];
int timer;

int** result;
int returnSize;

// add edge
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS
void dfs(int node, int parent) {
    visited[node] = 1;
    tin[node] = low[node] = timer++;

    struct Node* temp = adj[node];

    while(temp != NULL) {
        int neighbor = temp->val;

        if(neighbor == parent) {
            temp = temp->next;
            continue;
        }

        if(!visited[neighbor]) {
            dfs(neighbor, node);

            if(low[neighbor] < low[node])
                low[node] = low[neighbor];

            // bridge
            if(low[neighbor] > tin[node]) {
                result[returnSize] = (int*)malloc(2 * sizeof(int));
                result[returnSize][0] = node;
                result[returnSize][1] = neighbor;
                returnSize++;
            }
        } else {
            if(tin[neighbor] < low[node])
                low[node] = tin[neighbor];
        }

        temp = temp->next;
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSizeOut,
                         int** returnColumnSizes) {

    // initialize
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // build graph
    for(int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        addEdge(u, v);
        addEdge(v, u);
    }

    result = (int**)malloc(sizeof(int*) * connectionsSize);
    returnSize = 0;
    timer = 0;

    dfs(0, -1);

    // column sizes
    *returnColumnSizes = (int*)malloc(sizeof(int) * returnSize);
    for(int i = 0; i < returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    *returnSizeOut = returnSize;
    return result;
}