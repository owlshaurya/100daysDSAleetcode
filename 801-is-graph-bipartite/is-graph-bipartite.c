#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {

    int color[100];  // since n <= 100

    // initialize
    for(int i = 0; i < graphSize; i++)
        color[i] = -1;

    int queue[100];

    // handle disconnected graph
    for(int i = 0; i < graphSize; i++) {

        if(color[i] == -1) {

            int front = 0, rear = 0;

            queue[rear++] = i;
            color[i] = 0;

            while(front < rear) {
                int node = queue[front++];

                for(int j = 0; j < graphColSize[node]; j++) {
                    int neighbor = graph[node][j];

                    // not colored
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        queue[rear++] = neighbor;
                    }
                    // same color → conflict
                    else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}