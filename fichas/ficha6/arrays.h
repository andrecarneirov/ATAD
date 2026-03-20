/**
 * @file arrays.h
 * @brief Dynamic array utility functions.
 */

#pragma once

/**
 * @brief Prints the contents of an integer array.
 *
 * @param arr       [in] array to print (NULL prints a message)
 * @param arrLength [in] number of elements
 */
void arrayPrint(int *arr, int arrLength);

/**
 * @brief Fills an array with random integers in [0, 50].
 *
 * @param arr       [out] array to fill
 * @param arrLength [in]  number of elements
 */
void arrayFillRandom(int arr[], int arrLength);

/**
 * @brief Creates a new dynamically allocated array with only the even values.
 *
 * The caller is responsible for freeing the returned array.
 *
 * @param arr          [in]  source array
 * @param arrLength    [in]  number of elements in source
 * @param filterLength [out] number of even elements found
 * @return int* pointer to the new array, or NULL if none found / alloc fails
 */
int* arrayFilterEven(int arr[], int arrLength, int *filterLength);