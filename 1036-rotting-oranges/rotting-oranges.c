#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = gridColSize[0];

    int queue[100][2];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: Add rotten oranges to queue
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            if(grid[i][j] == 1)
                fresh++;
        }
    }

    int minutes = 0;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // BFS
    while(front < rear && fresh > 0) {

        int size = rear - front;

        for(int i = 0; i < size; i++) {

            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for(int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {

                    grid[nx][ny] = 2; // rot it
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;

                    fresh--;
                }
            }
        }

        minutes++;
    }

    if(fresh > 0)
        return -1;

    return minutes;
}