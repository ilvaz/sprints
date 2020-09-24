#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    if (src == NULL) {
        return NULL;
    }
    int dup_count = 0;
    for (int i = 0; i < src_size - 1; i++) {
        for (int j = i + 1; j < src_size; j++) {
            if (src[i] == src[j]) {
                dup_count++;
            }
        }
    }
    dst_size[0] = src_size - dup_count;
    int *result = malloc(dst_size[0]);
    int d = dst_size[0] - 1;
    bool is_dup;
    for (int i = src_size - 1; i >= 0; i--) {
        is_dup = false;
        for (int j = i - 1; j >=  0; j--) {
            if (src[i] == src[j]) {
                is_dup = true;
            }
        }
        if (!is_dup && d >=0) {
            result[d] = src[i];
            d--;
        }
    }
    return result;
}

