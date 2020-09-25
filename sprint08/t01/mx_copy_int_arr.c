#include <stdio.h>
#include <stdlib.h>
#include "duplicate.h"

int *mx_copy_int_arr(const int *src, int size) {
    if (src == NULL) {
        return NULL;
    }
    int *arr = malloc(size);
    if (arr == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++){
        arr[i] = src[i];
    }
    return arr;
}

