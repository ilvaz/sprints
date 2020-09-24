#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool mx_isspace(char c);

char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);

char *mx_strnew(const int size);

void mx_strdel(char **str);

char *mx_strtrim(const char *str);

char *mx_strtrim(const char *str) {
    char *tmp = mx_strnew(mx_strlen(str));
    int j = 0;
    for (int i = 0; i < mx_strlen(str) - 1; i++){
        if (str[i] > 32) {
            tmp[j] = str[i];
            j++;
        }
        else if (j != 0 && mx_isspace(str[i]) && str[i + 1] > 32) {
            tmp[j] = str[i];
            j++;
        }
    }
    char *result = mx_strnew(j);
    mx_strcpy(result, tmp);
    free(tmp);
    return result;
}

