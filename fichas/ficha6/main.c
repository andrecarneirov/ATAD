#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"

int main() {
    srand(time(NULL));

    int len;
    int *v = NULL;

    /* Section 2 - allocate */
    printf("How many values? ");
    scanf("%d", &len);

    v = (int*) calloc(len, sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("After calloc:    ");
    arrayPrint(v, len);

    /* Section 4 - fill with random values */
    arrayFillRandom(v, len);
    printf("After random:    ");
    arrayPrint(v, len);

    /* Section 5 - filter even values */
    int countEven;
    int *evenArr = arrayFilterEven(v, len, &countEven);

    printf("Even values (%d): ", countEven);
    arrayPrint(evenArr, countEven);

    /* Section 3/6 - free all dynamic memory */
    free(v);
    free(evenArr);

    return EXIT_SUCCESS;
}