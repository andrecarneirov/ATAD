/**
 * @file arrays.c
 * @brief Implementation of array utility functions.
 */

#include "arrays.h"

bool arrayMean(int arr[], int arrLength, double *mean) {
    if (arrLength <= 0) return false;

    int sum = 0;
    for (int i = 0; i < arrLength; i++) {
        sum += arr[i];
    }
    *mean = (double)sum / arrLength;
    return true;
}

bool arrayStats(int arr[], int arrLength, int *min, int *max, double *mean) {
    if (arrLength <= 0) return false;

    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }

    arrayMean(arr, arrLength, mean); /* reuse ex. 3 */
    return true;
}