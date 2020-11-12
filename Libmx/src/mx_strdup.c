#include "libmx.h" 

char *mx_strdup(const char *str) {
    char *string = mx_strnew(mx_strlen(str));
    mx_strcpy(string, str);
    return string;
}
