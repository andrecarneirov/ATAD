#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input.h"

int main() {

    printf("--- QUADRATIC EQUATION SOLVER a^2 + bx + c = 0 ---\n\n");

    int a, b, c;

    printf("a?: ");
    while (!readInteger(&a)) {
        printf("Valor invalido. Tente novamente.\na?: ");
    }

    printf("b?: ");
    while (!readInteger(&b)) {
        printf("Valor invalido. Tente novamente.\nb?: ");
    }

    printf("c?: ");
    while (!readInteger(&c)) {
        printf("Valor invalido. Tente novamente.\nc?: ");
    }

    double discriminant = (double)(b * b) - 4.0 * a * c;

    if (discriminant < 0) {
        printf("\nA equacao nao tem solucao real (discriminante negativo).\n");
    } else {
        double x1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double x2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("\nx = {%.2f, %.2f}\n", x1, x2);
    }

    return EXIT_SUCCESS;
}