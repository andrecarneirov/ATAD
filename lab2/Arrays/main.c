#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main() {

    printf("--- Arrays ---\n\n");

    int arr[] = {1, 4, 7, 10, 14, 15};
    int length = 6;

    // Crescente
    arrayPrint(arr, length);
    int sorted = arrayIsSorted(arr, length);
    printf("Detected sorting = %s\n\n",
           sorted == 1 ? "increasing" : sorted == -1 ? "decreasing" : "none");

    // Inverter -> Decrescente
    arrayReverse(arr, length);
    arrayPrint(arr, length);
    sorted = arrayIsSorted(arr, length);
    printf("Detected sorting = %s\n\n",
           sorted == 1 ? "increasing" : sorted == -1 ? "decreasing" : "none");

    // Trocar índices 1 e 3 -> Nenhuma ordenação
    int temp = arr[1];
    arr[1] = arr[3];
    arr[3] = temp;
    arrayPrint(arr, length);
    sorted = arrayIsSorted(arr, length);
    printf("Detected sorting = %s\n",
           sorted == 1 ? "increasing" : sorted == -1 ? "decreasing" : "none");

    return EXIT_SUCCESS;
}