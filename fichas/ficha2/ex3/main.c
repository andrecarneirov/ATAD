#include <stdio.h>
#include <stdbool.h>
#include "arrays.h"

int main() {
    int values[] = {0, 1, 2, 7, 10, 14, 17};
    int length = 7;

    printf("Array: ");
    arrayPrint(values, length);

    printf("Even count: %d\n", arrayCountEven(values, length));
    printf("Sum: %d\n", arraySum(values, length));
    printf("Contains 7? %s\n", arrayContains(7, values, length) ? "Yes" : "No");
    printf("Contains 5? %s\n", arrayContains(5, values, length) ? "Yes" : "No");

    return 0;
}