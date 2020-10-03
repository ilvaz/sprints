#include "matrix.h"

char *mx_strnew(const int size) {
    char *s = malloc(size + 1);
    for (int i = 0; i <= size; i++) {
        s[i] = '\0';
    }
    return s;
}

int mx_strlen(const char *s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

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

