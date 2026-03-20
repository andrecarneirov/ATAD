#include <stdio.h>
#include <string.h>
#include "expenses.h"

Expense expenseCreate(const char *description, float value) {
    Expense e;
    strncpy(e.description, description, 49);
    e.description[49] = '\0';
    e.value = value;
    return e;
}

void expensePrint(Expense e) {
    printf("Despesa[Descricao: %s, Valor: %.2f€]\n", e.description, e.value);
}

float expensesTotal(Expense arr[], int length) {
    float total = 0;
    for (int i = 0; i < length; i++) {
        total += arr[i].value;
    }
    return total;
}