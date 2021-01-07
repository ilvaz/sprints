#include "matrix.h"

char *mx_addchar(char *s, char c)  {
    int size = mx_strlen(s) + 1;
    char *result = mx_strnew(size);
    result = mx_strdup(s);
    result[size - 1] = c;
    result[size] = '\0';
    return result;
}
