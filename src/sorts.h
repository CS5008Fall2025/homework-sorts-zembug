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
    //return 0; // modify to return the index of the min value
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
    if (array == NULL || size == 0) {
        return;
        
    }
    for (unsigned int i = 0; i < size - 1; i++) // iterate through the array
    {
        int minimumIndex = findMinimum(array, i, size); // finf index of minimum value in unsorted part of array
        if (minimumIndex != i) // if the minimum value is not at the current position
        {
            int temp = array[i]; // swap the minimum value with the current position
            array[i] = array[minimumIndex];
            array[minimumIndex] = temp; 
        }
        if (print) // if print is true, print the array after each iteration
        {
            printIntArray(array, size);
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
    if (array == NULL || size == 0) {
        return;
    }

    for (unsigned int i = 1; i < size; i++) // iterate through the array starting from the second element
    {
        int key = array[i]; // the current element to be inserted
        int j = i - 1; // the index of the last element in the sorted part of the array

        // Move elements of array[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key; // insert the key at its correct position

        if (print) // if print is true, print the array after each iteration
        {
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
    // code generated from lab

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