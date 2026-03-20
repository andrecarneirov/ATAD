#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"
#include "arrays.h"

/* ─────────────────────────────────────────
 * Exercise 1 – Double a value
 * ───────────────────────────────────────── */
void doubleValue(int *val) {
    *val = *val * 2;
}

/* ─────────────────────────────────────────
 * Exercise 2 – String length (pointer arithmetic only, no indexing)
 * ───────────────────────────────────────── */
int stringLength(char *str) {
    char *p = str;
    while (*p != '\0') {
        p++;
    }
    return (int)(p - str);
}

int main() {

    /* ── Exercise 1 ── */
    printf("=== Exercise 1: doubleValue ===\n");
    int x = 7;
    printf("Before: %d\n", x);
    doubleValue(&x);
    printf("After:  %d\n\n", x);

    /* ── Exercise 2 ── */
    printf("=== Exercise 2: stringLength ===\n");
    printf("stringLength(\"Ponteiros\") = %d\n", stringLength("Ponteiros"));
    printf("stringLength(\"\")          = %d\n", stringLength(""));
    printf("stringLength(\"Hello!\")    = %d\n\n", stringLength("Hello!"));

    /* ── Exercise 3 ── */
    printf("=== Exercise 3: arrayMean ===\n");
    int arr1[]  = {10, 20, 30, 40, 50};
    int len1    = sizeof(arr1) / sizeof(arr1[0]);
    double mean = 0.0;

    if (arrayMean(arr1, len1, &mean)) {
        printf("Mean of {10,20,30,40,50} = %.2f\n", mean);
    }
    if (!arrayMean(NULL, 0, &mean)) {
        printf("Empty array: arrayMean returned false\n");
    }
    printf("\n");

    /* ── Exercise 4 ── */
    printf("=== Exercise 4: arrayStats ===\n");
    int arr2[]   = {3, 17, -5, 42, 8, 1};
    int len2     = sizeof(arr2) / sizeof(arr2[0]);
    int minVal, maxVal;
    double meanVal;

    if (arrayStats(arr2, len2, &minVal, &maxVal, &meanVal)) {
        printf("Array: {3, 17, -5, 42, 8, 1}\n");
        printf("  Min  = %d\n", minVal);
        printf("  Max  = %d\n", maxVal);
        printf("  Mean = %.2f\n", meanVal);
    }
    if (!arrayStats(NULL, 0, &minVal, &maxVal, &meanVal)) {
        printf("Empty array: arrayStats returned false\n");
    }

    return EXIT_SUCCESS;
}