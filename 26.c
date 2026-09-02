#include <string.h>

// annotation: memory inefficient, but runtime efficient (each number needs to get touched less often)

int removeDuplicates(int* nums, const int numsSize) {

    // if the array length is less than 2, duplicates are impossible
    if (numsSize <= 1) return numsSize;

    // prepare new array
    int nums_unique[numsSize];
    int nums_unique_index = 0;

    // fill array with first value (required for checking for duplicates in loop)
    nums_unique[nums_unique_index++] = nums[0];

    // scan numbers and save uniques
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums_unique[nums_unique_index - 1]) continue;
        nums_unique[nums_unique_index++] = nums[i];
    }

    // overwrite nums array with unique nums array
    memmove(nums, nums_unique, numsSize * sizeof(int));

    // return amount of unique numbers
    return nums_unique_index;
}