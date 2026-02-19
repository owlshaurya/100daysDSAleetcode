#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) 
{
    int total = 0;

    int curMax = 0, maxSum = INT_MIN;
    int curMin = 0, minSum = INT_MAX;

    for (int i = 0; i < numsSize; i++)
    {
        int x = nums[i];

        // Kadane for max subarray
        curMax = max(x, curMax + x);
        maxSum = max(maxSum, curMax);

        // Kadane for min subarray
        curMin = min(x, curMin + x);
        minSum = min(minSum, curMin);

        total += x;
    }

    // if all elements are negative
    if (maxSum < 0)
        return maxSum;

    // circular case
    return max(maxSum, total - minSum);
}