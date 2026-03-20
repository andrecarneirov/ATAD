#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input.h"

void change(double money) {
    int cents = (int)round(money * 100);

    int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    double labels[]     = {5,   2,   1,   0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    int size = 9;

    printf("\nReceives (%.2f€) by:\n", money);
    printf("%-8s x Amount\n", "Value");

    for (int i = 0; i < size; i++) {
        int amount = cents / denominations[i];
        cents      = cents % denominations[i];

        // print label: use integer format if whole number, decimal otherwise
        if (denominations[i] >= 100) {
            printf("%.0f€%-5s x %d\n", labels[i], "", amount);
        } else {
            printf("%.2f€%-3s x %d\n", labels[i], "", amount);
        }
    }
}

int main() {
    double total, pay;

    printf("--- PAYMENT ---\n\n");

    printf("Total (€)?: ");
    while (!readDouble(&total)) {
        printf("Invalid input. Total (€)?: ");
    }

    printf("Pay (€)?: ");
    while (!readDouble(&pay)) {
        printf("Invalid input. Pay (€)?: ");
    }

    if (pay < total) {
        printf("Error: payment is less than total.\n");
        return EXIT_FAILURE;
    }

    change(pay - total);

    return EXIT_SUCCESS;
}