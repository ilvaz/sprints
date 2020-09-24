#include <stdio.h>
#include <stdlib.h>

void mx_strdel(char **str);

void mx_strdel(char **str) {
    int i = 0;
    while (str[i] != NULL) {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
    str = NULL;
}

