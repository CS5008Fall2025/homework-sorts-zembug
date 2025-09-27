#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    int minimumIndex = start; // assume the first index is the minimum                  
    for (int i = start + 1; i < stop; i++) // iterate from start to stop
    {
        if (array[i] < array[minimumIndex]) // find the index of the minimum value
        {
            minimumIndex = i; // update min index
        }
    }
    return minimumIndex; 
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    if (array == NULL || size == 0) { // if array is null or 0 return
        return;   
    }
    for (unsigned int i = 0; i < size - 1; i++) // iterate through the array, except last element
    {
        int minimumIndex = findMinimum(array, (int)i, (int)size); // find index of smallest element in unsorted part of array
        if (minimumIndex != (int)i) // if the smallest is not in correct position, swap it
        {
            // swap current element with minimum element found
            int temp = array[i]; 
            array[i] = array[minimumIndex]; 
            array[minimumIndex] = temp; 
        }
        if (print) { // if print is true, print the array after each iteration
            printIntArray(array, size); // print the array
        }
    }
}
/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    if (array == NULL || size == 0) { // if array is null or 0 return  
        return;
    }
    for (unsigned int i = 1; i < size; i++) // iterate through the array starting from the second element
    {
        int currentValue = array[i]; // the current element to be inserted
        int j = (int)i - 1; // the index of the last element in the sorted part of the array

        while (j >= 0 && array[j] > currentValue) //shift elements > current value to the right
        {
            array[j + 1] = array[j]; // shift element to the right
            j--; // move to the previous element
        }
        array[j + 1] = currentValue; // insert the key at its correct position

        if (print) { // if print is true, print the array after each iteration
            printIntArray(array, size);
        }
    }

}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    // outer loop
    for(unsigned int i = 0; i < size; i++) { // iterate through the array
        int swapped = 0; // flag to check if any swapping occurred
        // inner loop   
        for(unsigned int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1; // set flag to true if swapping occurred
            }
        }
        if(!swapped) {
            break; // if no swapping occurred, the array is sorted
        }
        if(print) {
            printIntArray(array, size); // print the array after each outer loop iteration
        }
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;


}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
   
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif