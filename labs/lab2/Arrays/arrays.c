#include <stdio.h>
#include "arrays.h"

void arrayPrint(int arr[], int arrLength) {
    printf("[");
    for (int i = 0; i < arrLength; i++) {
        printf("%d", arr[i]);
        if (i < arrLength - 1) printf(", ");
    }
    printf("]\n");
}

void arrayReverse(int arr[], int arrLength) {
    for (int i = 0; i < arrLength / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrLength - 1 - i];
        arr[arrLength - 1 - i] = temp;
    }
}

int arrayIsSorted(int arr[], int arrLength) {
    int increasing = 1, decreasing = 1;

    for (int i = 0; i < arrLength - 1; i++) {
        if (arr[i] >= arr[i + 1]) increasing = 0;
        if (arr[i] <= arr[i + 1]) decreasing = 0;
    }

    if (increasing) return 1;
    if (decreasing) return -1;
    return 0;
}