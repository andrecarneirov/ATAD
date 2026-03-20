#pragma once

/**
 * @brief Prints the elements of an array.
 * 
 * @param arr The array to be printed.
 * @param arrLength The length of the array.
 */
void arrayPrint(int arr[], int arrLength);


/**
 * @brief Performs a sequential search in an array.
 * 
 * @param val The value to search for.
 * @param arr The array to search in.
 * @param arrLength The length of the array.
 * @return The index of the value if found, otherwise -1.
 */
int sequentialSearch(int val, int arr[], int arrLength);

/**
 * @brief Finds the index of the maximum element in an array.
 * 
 * @param arr The array to search in.
 * @param arrLength The length of the array.
 * @return The index of the maximum element.
 */
int maximumIndex(int arr[], int arrLength);

/**
 * @brief Finds the index of the minimum element in an array.
 * 
 * @param arr The array to search in.
 * @param arrLength The length of the array.
 * @return The index of the minimum element.
 */
int minimumIndex(int arr[], int arrLength);

/**
 * @brief Sorts an array in ascending order using the Bubble Sort algorithm.
 * 
 * @param arr The array to be sorted.
 * @param arrLength The length of the array.
 */
void bubbleSortAscending(int arr[], int arrLength);

/**
 * @brief Sorts an array in descending order using the Selection Sort algorithm.
 * 
 * @param arr The array to be sorted.
 * @param arrLength The length of the array.
 */
void selectionSortDescending(int arr[], int arrLength);
