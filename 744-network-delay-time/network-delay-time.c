#include <stdlib.h>
#include <limits.h>

#define MAX 105

// Dijkstra using simple array (since constraints small)
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {

    int graph[MAX][MAX];

    // Initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Fill edges
    for(int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        graph[u][v] = w;
    }

    int dist[MAX];
    int visited[MAX] = {0};

    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;

    // Dijkstra
    for(int i = 1; i <= n; i++) {

        int u = -1;

        // find min distance node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if(dist[u] == INT_MAX)
            break;

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Find max distance
    int maxTime = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX)
            return -1;

        if(dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}