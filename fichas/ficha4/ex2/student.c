#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student studentCreate(char *name, char *number, int grade) {
    Student student;
    strcpy(student.name, name);
    strcpy(student.number, number);
    student.grade = grade;
    return student;
}

void studentPrint(Student s) {
    printf("%-30s | %-12s | %d\n", s.name, s.number, s.grade);
}

/* --- Ex. 1 --- */
bool studentExistsByName(char name[], Student arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

/* --- Ex. 2 --- */
int studentMinimumGradeIndex(Student arr[], int arrLength) {
    if (arrLength <= 0) return -1;

    int minIdx = 0;
    for (int i = 1; i < arrLength; i++) {
        if (arr[i].grade < arr[minIdx].grade) {
            minIdx = i;
        }
    }
    return minIdx;
}

/* --- Ex. 3 --- */
Student studentMaximumGrade(Student arr[], int arrLength) {
    Student empty = studentCreate("", "", -1);
    if (arrLength <= 0) return empty;

    int maxIdx = 0;
    for (int i = 1; i < arrLength; i++) {
        if (arr[i].grade > arr[maxIdx].grade) {
            maxIdx = i;
        }
    }
    return arr[maxIdx];
}

/* --- Ex. 4 + 6: Bubble Sort descending by grade; tie-break by name ascending --- */
void studentArrSortByGrade(Student arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = 0; j < arrLength - 1 - i; j++) {
            int swap = 0;
            if (arr[j].grade < arr[j + 1].grade) {
                swap = 1;
            } else if (arr[j].grade == arr[j + 1].grade) {
                /* tie-break: ascending by name */
                if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                    swap = 1;
                }
            }
            if (swap) {
                Student temp  = arr[j];
                arr[j]        = arr[j + 1];
                arr[j + 1]    = temp;
            }
        }
    }
}

/* --- Ex. 5: Selection Sort ascending by name --- */
void studentArrSortByName(Student arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arrLength; j++) {
            if (strcmp(arr[j].name, arr[minIdx].name) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Student temp  = arr[i];
            arr[i]        = arr[minIdx];
            arr[minIdx]   = temp;
        }
    }
}