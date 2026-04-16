#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {

    int color[graphSize];

    // initialize colors
    for(int i = 0; i < graphSize; i++)
        color[i] = -1;

    int queue[graphSize];

    for(int i = 0; i < graphSize; i++) {

        if(color[i] == -1) {

            int front = 0, rear = 0;

            queue[rear++] = i;
            color[i] = 0;

            while(front < rear) {
                int node = queue[front++];

                for(int j = 0; j < graphColSize[node]; j++) {
                    int neighbor = graph[node][j];

                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        queue[rear++] = neighbor;
                    }
                    else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}