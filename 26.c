#include <string.h>

// TODO: review

int removeDuplicates(int* nums, const int numsSize) {

    // nums.length == (0 || 1)
    if (numsSize <= 1) return numsSize;

    // prepare new array
    int nums_unique[numsSize];
    int nums_unique_index = 0;

    // fill array with first value
    nums_unique[nums_unique_index] = nums[0];
    nums_unique_index++;

    // scan numbers and save uniques
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums_unique[nums_unique_index - 1]) continue;
        nums_unique[nums_unique_index] = nums[i];
        nums_unique_index++;
    }

    // overwrite nums with unique nums
    memmove(nums, nums_unique, numsSize * sizeof(int));
    // return amount of unique numbers
    return nums_unique_index;
}
