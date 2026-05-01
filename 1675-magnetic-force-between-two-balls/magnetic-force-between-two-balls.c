#include <stdlib.h>

// comparator for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// check feasibility
int canPlace(int* pos, int n, int m, int dist) {
    int count = 1;          // first ball placed
    int last = pos[0];

    for(int i = 1; i < n; i++) {
        if(pos[i] - last >= dist) {
            count++;
            last = pos[i];
        }
        if(count >= m)
            return 1;
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {

    // Step 1: sort
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    // Step 2: binary search
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlace(position, positionSize, m, mid)) {
            ans = mid;        // possible
            low = mid + 1;    // try larger distance
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
