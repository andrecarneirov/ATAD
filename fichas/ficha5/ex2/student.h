#pragma once

#include <stdbool.h>

typedef struct student {
    char name[200];
    char number[12];
    int grade;
} Student;

typedef struct student* PtStudent;

/**
 * @brief Creates and initializes a student.
 *
 * @param name   [in] student name
 * @param number [in] student number
 * @param grade  [in] student grade
 * @return Student struct
 */
Student studentCreate(char *name, char *number, int grade);

/**
 * @brief Prints a student's information.
 *
 * @param s [in] pointer to the student to print
 */
void studentPrint(PtStudent s);

/**
 * @brief Checks whether two pointers reference the same instance.
 *
 * Compares memory addresses, not contents.
 *
 * @param s1 [in] pointer to first student
 * @param s2 [in] pointer to second student
 * @return true  if s1 and s2 point to the same address
 * @return false otherwise
 */
bool studentSame(PtStudent s1, PtStudent s2);

/**
 * @brief Checks whether two students have equal field values.
 *
 * @param s1 [in] pointer to first student
 * @param s2 [in] pointer to second student
 * @return true  if name, number and grade are all equal
 * @return false otherwise
 */
bool studentEquals(PtStudent s1, PtStudent s2);