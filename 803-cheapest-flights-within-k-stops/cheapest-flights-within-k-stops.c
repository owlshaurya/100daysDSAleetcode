#include <stdlib.h>
#include <limits.h>

#define MAX 105

struct Node {
    int city;
    int cost;
    int stops;
};

// Queue
struct Node queue[10000];
int front = 0, rear = 0;

void push(int city, int cost, int stops) {
    queue[rear].city = city;
    queue[rear].cost = cost;
    queue[rear].stops = stops;
    rear++;
}

struct Node pop() {
    return queue[front++];
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize,
                      int src, int dst, int k) {

    int graph[MAX][MAX];

    // Initialize graph
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = -1;
        }
    }

    // Fill graph
    for(int i = 0; i < flightsSize; i++) {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        graph[u][v] = w;
    }

    int cost[MAX];
    for(int i = 0; i < n; i++)
        cost[i] = INT_MAX;

    // Start from source
    push(src, 0, 0);
    cost[src] = 0;

    int ans = INT_MAX;

    while(front < rear) {
        struct Node curr = pop();

        int city = curr.city;
        int currCost = curr.cost;
        int stops = curr.stops;

        if(stops > k)
            continue;

        for(int i = 0; i < n; i++) {
            if(graph[city][i] != -1) {
                int newCost = currCost + graph[city][i];

                if(newCost < cost[i]) {
                    cost[i] = newCost;
                    push(i, newCost, stops + 1);
                }
            }
        }
    }

    if(cost[dst] == INT_MAX)
        return -1;

    return cost[dst];
}