#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    // initialize adjacency list
    for(int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // build graph
    for(int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;  // b → a
        indegree[a]++;
    }

    // queue
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    // BFS
    while(front < rear) {
        int curr = queue[front++];
        result[count++] = curr;

        for(int i = 0; i < adjSize[curr]; i++) {
            int neighbor = adj[curr][i];

            indegree[neighbor]--;

            if(indegree[neighbor] == 0)
                queue[rear++] = neighbor;
        }
    }

    // check cycle
    if(count != numCourses) {
        *returnSize = 0;
        return result;
    }

    *returnSize = numCourses;
    return result;
}