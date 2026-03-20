#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "input.h"

int loadStudents(Student arr[], int howMany);

int main() {

    Student students[200];
    int n = loadStudents(students, 60);

    /* ── Exercise 5: studentPrint ── */
    printf("=== Exercise 5: studentPrint ===\n");
    for (int i = 0; i < n; i++) {
        printf("--- Student[%d] ---\n", i);
        studentPrint(&students[i]);
    }

    /* ── Exercise 6: studentSame & studentEquals ── */
    printf("\n=== Exercise 6: studentSame & studentEquals ===\n");

    /* studentSame: same pointer → true */
    PtStudent p1 = &students[0];
    PtStudent p2 = &students[0];
    printf("studentSame(p1, p1)      -> %s (expected: true)\n",
           studentSame(p1, p2) ? "true" : "false");

    /* studentSame: different pointer → false */
    PtStudent p3 = &students[1];
    printf("studentSame(p1, p3)      -> %s (expected: false)\n",
           studentSame(p1, p3) ? "true" : "false");

    /* studentEquals: copy with same data → true */
    Student copy = studentCreate(students[0].name,
                                 students[0].number,
                                 students[0].grade);
    PtStudent p4 = &copy;
    printf("studentEquals(p1, copy)  -> %s (expected: true)\n",
           studentEquals(p1, p4) ? "true" : "false");

    /* studentEquals: two different students → false */
    printf("studentEquals(p1, p3)    -> %s (expected: false)\n",
           studentEquals(p1, p3) ? "true" : "false");

    return EXIT_SUCCESS;
}

int loadStudents(Student arr[], int howMany) {

    FILE *stream = fopen("students.csv", "r");
    if (!stream) {
        fprintf(stderr, "Error: could not open students.csv\n");
        return 0;
    }

    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), stream)) {
        if (count == howMany) break;

        char *tmp = strdup(line);
        char **tokens = splitString(tmp, 3, ";");

        int grade = atoi(tokens[2]);
        arr[count++] = studentCreate(tokens[0], tokens[1], grade);

        free(tokens);
        free(tmp);
    }

    fclose(stream);
    return count;
}