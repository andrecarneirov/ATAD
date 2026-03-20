#include <ctype.h>
#include <stdbool.h>
#include "strings.h"

int strLength(char str[]) {
    int count = 0;
    while (str[count] != '\0') count++;
    return count;
}

bool strOnlyLetters(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') continue;
        if (!isalpha(str[i])) return false;
    }
    return true;
}

void strToUpper(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

bool strEqualsIgnoreCase(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (tolower(str1[i]) != tolower(str2[i])) return false;
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

bool strHasDuplicates(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) continue;
        for (int j = i + 1; str[j] != '\0'; j++) {
            if (isspace(str[j])) continue;
            if (tolower(str[i]) == tolower(str[j])) return true;
        }
    }
    return false;
}