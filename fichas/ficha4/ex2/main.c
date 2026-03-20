#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "input.h"

#define MAX_STUDENTS 200
#define CSV_FILE     "students.csv"

int loadStudents(const char *filename, Student arr[], int maxLen) {
    FILE *f = fopen(filename, "r");
    if (!f) { printf("Erro ao abrir %s\n", filename); return 0; }
    int count = 0;
    char line[256];
    while (count < maxLen && fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = '\0';
        char *name   = strtok(line, ";");
        char *number = strtok(NULL, ";");
        char *gradeS = strtok(NULL, ";");
        if (name && number && gradeS)
            arr[count++] = studentCreate(name, number, atoi(gradeS));
    }
    fclose(f);
    return count;
}

void printAll(Student arr[], int n) {
    printf("%-30s | %-12s | %s\n", "Nome", "Numero", "Nota");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < n; i++) studentPrint(arr[i]);
    printf("\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int n = loadStudents(CSV_FILE, students, MAX_STUDENTS);
    printf("Carregados %d estudantes.\n\n", n);

    /* Ex. 1 */
    char name[200];
    printf("Pesquisar estudante por nome: ");
    readString(name, sizeof(name));
    if (studentExistsByName(name, students, n))
        printf("Estudante \"%s\" encontrado!\n\n", name);
    else
        printf("Estudante \"%s\" nao encontrado.\n\n", name);

    /* Ex. 2 */
    int minIdx = studentMinimumGradeIndex(students, n);
    printf("Estudante com nota minima:\n");
    studentPrint(students[minIdx]);
    printf("\n");

    /* Ex. 3 */
    Student best = studentMaximumGrade(students, n);
    printf("Estudante com nota maxima:\n");
    studentPrint(best);
    printf("\n");

    /* Ex. 4 + 6 */
    printf("Ordenado por nota (decrescente, empate por nome):\n");
    studentArrSortByGrade(students, n);
    printAll(students, n);

    /* Ex. 5 */
    printf("Ordenado por nome (crescente):\n");
    studentArrSortByName(students, n);
    printAll(students, n);

    return EXIT_SUCCESS;
}