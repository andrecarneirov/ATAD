#pragma once

/**
 * @brief Prints an array to the console.
 * 
 * @param arr [in] the array to print
 * @param arrLength [in] number of elements in the array
 */
void arrayPrint(int arr[], int arrLength);

/**
 * @brief Reverses the order of elements in an array.
 * 
 * @param arr [in/out] the array to reverse
 * @param arrLength [in] number of elements in the array
 */
void arrayReverse(int arr[], int arrLength);

/**
 * @brief Checks if an array is sorted.
 * 
 * @param arr [in] the array to check
 * @param arrLength [in] number of elements in the array
 * @return 1 if sorted in increasing order
 * @return -1 if sorted in decreasing order
 * @return 0 if not sorted
 */
int arrayIsSorted(int arr[], int arrLength);