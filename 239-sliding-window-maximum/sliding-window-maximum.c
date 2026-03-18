#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int deque[100000];
    int front = 0, rear = -1;
    
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++) {

        // Remove indices outside window
        if(front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        // Add current index
        deque[++rear] = i;

        // Store result when window size reached
        if(i >= k - 1)
            result[(*returnSize)++] = nums[deque[front]];
    }

    return result;
}