#include <stdio.h>
#include "arrays.h"

void arrayPrint(int arr[], int arrLength) {
    printf("[ ");
    for(int i=0; i<arrLength; i++) {
        printf("%d%s", arr[i], (i < arrLength - 1 ? ", " : ""));
    }
    printf("]\n");
}


int sequentialSearch(int val, int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int maximumIndex(int arr[], int arrLength) {
    if (arrLength <= 0) return -1;

    int maxIdx = 0;
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

int minimumIndex(int arr[], int arrLength) {
    if (arrLength <= 0) return -1;

    int minIdx = 0;
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void bubbleSortAscending(int arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = 0; j < arrLength - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp  = arr[j];
                arr[j]    = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSortDescending(int arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        /* find index of maximum in the unsorted portion [i .. arrLength-1] */
        int maxIdx = i;
        for (int j = i + 1; j < arrLength; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        /* swap maximum with the first unsorted element */
        if (maxIdx != i) {
            int temp    = arr[i];
            arr[i]      = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}