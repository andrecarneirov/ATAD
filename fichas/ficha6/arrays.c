/**
 * @file arrays.c
 * @brief Implementation of dynamic array utility functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

void arrayPrint(int *arr, int arrLength) {
    if (arr == NULL) {
        printf("(NULL array)\n");
        return;
    }
    printf("[");
    for (int i = 0; i < arrLength; i++) {
        printf("%d", arr[i]);
        if (i < arrLength - 1) printf(", ");
    }
    printf("]\n");
}

void arrayFillRandom(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        arr[i] = rand() % 51;   /* [0, 50] */
    }
}

/* Approach A: count evens first, then allocate exactly that size */
int* arrayFilterEven(int arr[], int arrLength, int *filterLength) {
    /* pass 1 - count */
    int count = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) count++;
    }

    *filterLength = count;

    if (count == 0) return NULL;

    /* pass 2 - allocate and fill */
    int *result = (int*) malloc(sizeof(int) * count);
    if (result == NULL) return NULL;

    int idx = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) result[idx++] = arr[i];
    }

    return result;
}