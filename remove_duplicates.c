#include <stdio.h>

// Function to remove duplicates from a sorted array
// Returns the new length of the array after duplicates have been removed

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0; // If the array is empty, no elemnts to process

    int k = 1; // Initialize the index to 1 since first element is unique

    for (int i = 1; i < numsSize; i++) { // Start from the second element
        if (nums[i] != nums[k - 1]) { // Compare with the last unique element
            nums[k] = nums[i]; // Place the unique element at index k
            k++; // Increment the index for the next unique element
        }
    }

    return k;
}