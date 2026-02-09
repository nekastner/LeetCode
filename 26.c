int removeDuplicates(int* nums, int numsSize) {
    int nums_filtered[numsSize];
    nums_filtered[0] = nums[0];
    int nums_filtered_i = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums_filtered[nums_filtered_i]) continue;
        nums_filtered[++nums_filtered_i] = nums[i];
        int duplicates_count = nums_filtered_i + 1;
        while (nums_filtered_i < numsSize) {
            nums_filtered[++nums_filtered_i] = -1;
        }
        return duplicates_count;
    }