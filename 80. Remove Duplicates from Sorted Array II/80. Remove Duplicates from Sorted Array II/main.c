#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;  // Handle empty array edge case
    
    int count = 1;  // We start counting the first occurrence of the first number
    int k = 1;      // k is the position where we place the next valid element

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;  // Increment count if the current number is the same as the previous
        } else {
            count = 1;  // Reset count when a new number is encountered
        }

        // If count is 2 or less, we keep the current number
        if (count <= 2) {
            nums[k] = nums[i];  // Place the current number in the next available position
            k++;  // Move the "valid" pointer
        }
    }

    // Return the new size of the array
    return k;
}

int main(int argc, const char * argv[]) {
    int num[] = {1, 1, 1, 2, 2, 3};
    int numsize = sizeof(num) / sizeof(num[0]);
    
    int newLength = removeDuplicates(num, numsize);  // Call function to remove duplicates

    printf("New array length: %d\n", newLength);
    // Print the modified array up to the new size
    for (int i = 0; i < newLength; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
