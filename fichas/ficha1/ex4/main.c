#include <stdio.h>
#include <stdbool.h>
#include "strings.h"

int main() {
    char str1[] = "Hello World 123";
    char str2[] = "hello world 123";
    char str3[] = "Programming in C";
    char str4[] = "Bright vex dwaf jump";

    printf("Length of '%s': %d\n", str1, strLength(str1));
    printf("'%s' only letters? %s\n", str1, strOnlyLetters(str1) ? "Yes" : "No");
    printf("'%s' only letters? %s\n", str3, strOnlyLetters(str3) ? "Yes" : "No");

    strToUpper(str1);
    printf("Uppercase: %s\n", str1);

    printf("'%s' == '%s' (case insensitive)? %s\n", str1, str2,
           strEqualsIgnoreCase(str1, str2) ? "Yes" : "No");
    printf("'%s' == '%s' (case insensitive)? %s\n", str1, str3,
           strEqualsIgnoreCase(str1, str3) ? "Yes" : "No");

    printf("'%s' has duplicates? %s\n", str1, strHasDuplicates(str1) ? "Yes" : "No");
    printf("'%s' has duplicates? %s\n", str4, strHasDuplicates(str4) ? "Yes" : "No");

    return 0;
}