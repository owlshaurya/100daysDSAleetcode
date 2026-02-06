void moveZeroes(int* nums, int numsSize) {
    int j = 0;   // points to position for next non-zero

    // Move all non-zero elements forward
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    // Fill remaining positions with zero
    while(j < numsSize) {
        nums[j++] = 0;
    }
}
