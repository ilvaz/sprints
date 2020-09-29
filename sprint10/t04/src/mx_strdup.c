#include <stdio.h>
#include <stdlib.h>

char *mx_strdup(const char *str) {
    int i = 0; 
    while (str[i] != '\0') {
        i++;
    }
    char *result = malloc(i + 1);
    for (int j = 0; j <= i; j++) {
        result[j] = str[j];
    }
    result[i + 1] = '\0';
    return result;
}
