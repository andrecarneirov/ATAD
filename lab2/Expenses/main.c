#include <stdio.h>
#include <stdlib.h>
#include "expenses.h"

int main() {

    printf("--- Gestao de Despesas Mensais ---\n\n");

    Expense despesas[3];
    despesas[0] = expenseCreate("Renda", 500.00);
    despesas[1] = expenseCreate("Alimentacao", 250.00);
    despesas[2] = expenseCreate("Transportes", 80.00);

    for (int i = 0; i < 3; i++) {
        expensePrint(despesas[i]);
    }

    printf("\nTotal: %.2f€\n", expensesTotal(despesas, 3));

    return EXIT_SUCCESS;
}