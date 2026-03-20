#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input.h"

int main() {
    int a, b, c;

    printf("--- QUADRATIC EQUATION SOLVER a^2 + bx + c = 0 ---\n\n");

    printf("a?: ");
    while (!readInteger(&a)) {
        printf("Invalid input. a?: ");
    }

    printf("b?: ");
    while (!readInteger(&b)) {
        printf("Invalid input. b?: ");
    }

    printf("c?: ");
    while (!readInteger(&c)) {
        printf("Invalid input. c?: ");
    }

    double discriminant = (double)(b * b) - 4.0 * a * c;

    if (discriminant < 0) {
        printf("\nNo real solutions (negative discriminant).\n");
    } else {
        double x1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double x2 = (-b - sqrt(discriminant)) / (2.0 * a);
        printf("\nx = {%.3f, %.3f}\n", x1, x2);
    }

    return EXIT_SUCCESS;
}