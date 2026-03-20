#pragma once

#include <stdbool.h>

typedef struct student {
    char name[200];
    char number[12];
    int grade;
} Student;

typedef struct student* PtStudent;

/**
 * @brief Creates and initializes a student
 */
Student studentCreate(char *name, char *number, int grade);

/**
 * @brief Prints a student's information
 */
void studentPrint(Student s);

/**
 * @brief Searches for the name of a student in an array of students
 * @param arr [in] The student's array.
 * @param arrLength [in] The size of the array.
 * @param name [in] The student's name.
 * @return true if the student exists, false otherwise.
 */
bool studentExistsByName(char name[], Student arr[], int arrLength);

/**
 * @brief Selects the student with the minimum grade in an array of students
 * @param arr [in] The student's array.
 * @param arrLength [in] The size of the array.
 * @return index of student with minimum grade, -1 if array is empty.
 */
int studentMinimumGradeIndex(Student arr[], int arrLength);

/**
 * @brief Selects the student with the maximum grade in an array of students
 * @param arr [in] The student's array.
 * @param arrLength [in] The size of the array.
 * @return copy of student with maximum grade, or 'empty' student if array is empty.
 */
Student studentMaximumGrade(Student arr[], int arrLength);

/**
 * @brief Sorts an array of students by grade (descending).
 *        In case of tie, sorts by name (ascending).
 * @param arr [in/out] The student's array.
 * @param arrLength [in] The size of the array.
 */
void studentArrSortByGrade(Student arr[], int arrLength);

/**
 * @brief Sorts an array of students by name (ascending).
 * @param arr [in/out] The student's array.
 * @param arrLength [in] The size of the array.
 */
void studentArrSortByName(Student arr[], int arrLength);