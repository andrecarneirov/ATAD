/**
 * @file arrays.h
 * @brief Array utility functions using pointers.
 */

#pragma once

#include <stdbool.h>

/**
 * @brief Computes the mean of an integer array.
 *
 * @param arr      [in]  array of integers
 * @param arrLength [in]  number of elements
 * @param mean     [out] address to write the mean into
 * @return true  if the mean was calculated successfully
 * @return false if the array is empty
 */
bool arrayMean(int arr[], int arrLength, double *mean);

/**
 * @brief Computes min, max and mean of an integer array.
 *
 * @param arr       [in]  array of integers
 * @param arrLength [in]  number of elements
 * @param min       [out] address to write the minimum value
 * @param max       [out] address to write the maximum value
 * @param mean      [out] address to write the mean value
 * @return true  if the array contains elements
 * @return false if the array is empty
 */
bool arrayStats(int arr[], int arrLength, int *min, int *max, double *mean);