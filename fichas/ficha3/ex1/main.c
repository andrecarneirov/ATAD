#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "arrays.h"

#define LEN 10

int main() {

    int v[LEN] = {26, 49, 1, 12, 2, 14, 29, 34, 44, 35};

    printf("Array inicial:\n");
    arrayPrint(v, LEN);

    /* --- 1. Sequential Search --- */
    int val;
    printf("\nInsira um numero a pesquisar: ");
    readInteger(&val);

    int index = sequentialSearch(val, v, LEN);
    if (index != -1) {
        printf("O numero %d existe na posicao %d do array!\n", val, index);
    } else {
        printf("O numero %d nao existe no array!\n", val);
    }

    /* --- 2. Maximum --- */
    int maxIdx = maximumIndex(v, LEN);
    printf("\nMaximo: v[%d] = %d\n", maxIdx, v[maxIdx]);

    /* --- 3. Minimum --- */
    int minIdx = minimumIndex(v, LEN);
    printf("Minimo: v[%d] = %d\n", minIdx, v[minIdx]);

    /* --- 4. Bubble Sort Ascending --- */
    int v2[LEN] = {26, 49, 1, 12, 2, 14, 29, 34, 44, 35};
    printf("\nBubble Sort (ascendente):\n");
    printf("Antes:  ");
    arrayPrint(v2, LEN);
    bubbleSortAscending(v2, LEN);
    printf("Depois: ");
    arrayPrint(v2, LEN);

    /* --- 5. Selection Sort Descending --- */
    int v3[LEN] = {26, 49, 1, 12, 2, 14, 29, 34, 44, 35};
    printf("\nSelection Sort (descendente):\n");
    printf("Antes:  ");
    arrayPrint(v3, LEN);
    selectionSortDescending(v3, LEN);
    printf("Depois: ");
    arrayPrint(v3, LEN);

    return EXIT_SUCCESS;
}