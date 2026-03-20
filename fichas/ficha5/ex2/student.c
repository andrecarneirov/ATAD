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

/* Exercise 5 ─────────────────────────────── */
void studentPrint(PtStudent s) {
    printf("Name:   %s\n", s->name);
    printf("Number: %s\n", s->number);
    printf("Grade:  %d\n", s->grade);
}

/* Exercise 6 ─────────────────────────────── */
bool studentSame(PtStudent s1, PtStudent s2) {
    return s1 == s2;   /* identity: same memory address */
}

bool studentEquals(PtStudent s1, PtStudent s2) {
    return strcmp(s1->name,   s2->name)   == 0 &&
           strcmp(s1->number, s2->number) == 0 &&
           s1->grade == s2->grade;
}