#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1; // Last index of valid elements in nums1
    int j = n - 1; // Last index of nums2
    int k = m + n - 1; // Last index of nums1 after merging

    // Merge nums1 and nums2 from the end to avoid overwriting nums1 elements
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    // No need to copy the remaining elements from nums1 because they're already in place.
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};  // nums1 with extra space for nums2
    int nums2[3] = {2, 5, 6};           // nums2 array
    int m = 3;                          // Number of valid elements in nums1
    int n = 3;                          // Number of elements in nums2

    // Calling the merge function
    merge(nums1, 6, m, nums2, 3, n);

    // Print the merged array
    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
