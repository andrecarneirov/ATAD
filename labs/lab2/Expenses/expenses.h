#pragma once

/**
 * @brief Represents a monthly expense.
 */
typedef struct {
    char description[50]; /**< Description of the expense (up to 50 chars) */
    float value;          /**< Value of the expense */
} Expense;

/**
 * @brief Creates and returns a new expense.
 * 
 * @param description [in] description of the expense
 * @param value [in] value of the expense
 * @return Expense the created expense
 */
Expense expenseCreate(const char *description, float value);

/**
 * @brief Prints an expense to the console.
 * 
 * @param e [in] the expense to print
 */
void expensePrint(Expense e);

/**
 * @brief Returns the total sum of an array of expenses.
 * 
 * @param arr [in] array of expenses
 * @param length [in] number of elements in the array
 * @return float the total sum
 */
float expensesTotal(Expense arr[], int length);