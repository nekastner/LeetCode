int maxDistance(const int* nums1, const int nums1Size, const int* nums2, const int nums2Size) {

    int maxPairI1 = 0, maxPairI2 = 0;

    // i1 must not be greater than i2
    for (int i1 = 0; i1 < (nums1Size < nums2Size ? nums1Size : nums2Size); i1++) {
        // i2 should be as much greater than i1 as possible
        for (int i2 = i1; i2 < nums2Size; i2++) {

            // value at i1 may not be greater than value at i2
            if (nums1[i1] > nums2[i2]) continue;

            // if the local pair is greater than the max one, update the max one with the local one
            if (i2 - i1 > maxPairI2 - maxPairI1) {
                maxPairI1 = i1;
                maxPairI2 = i2;
            }
        }
    }

    return maxPairI2 - maxPairI1;

    // TODO: takes to longc
}
