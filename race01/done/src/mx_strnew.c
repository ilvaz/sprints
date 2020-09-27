#include <stdlib.h>

char *mx_strnew(const int size);

char *mx_strnew(const int size) {
    char *tmp = (char*) malloc(size + 1);
    for (int i = 0; i <= size; i++){
        tmp[i] = '\0';
    }
    return tmp;
}
