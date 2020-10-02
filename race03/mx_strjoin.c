#include <stdio.h>
#include <stdlib.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);

char *mx_strjoin(const char *s1, const char *s2) {
    int size = mx_strlen(s1) + mx_strlen(s2);
    char *result = mx_strnew(size);
    result = mx_strdup(s1);
    mx_strcat(result, s2);
    result[size] = '\0';
    return result;
}
