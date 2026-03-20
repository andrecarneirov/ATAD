#include <stdio.h>
#include <stdbool.h>
#include "arrays.h"

void arrayPrint(int arr[], int arrLength) {
    printf("[");
    for (int i = 0; i < arrLength; i++) {
        printf("%d", arr[i]);
        if (i < arrLength - 1) printf(", ");
    }
    printf("]\n");
}

int arrayCountEven(int arr[], int arrLength) {
    int count = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}

int arraySum(int arr[], int arrLength) {
    int sum = 0;
    for (int i = 0; i < arrLength; i++) {
        sum += arr[i];
    }
    return sum;
}

bool arrayContains(int val, int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}