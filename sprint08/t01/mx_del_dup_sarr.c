#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (src == NULL) {
        return NULL;
    }
    int dup_count = 0;
    for (int i = 0; i < src->size - 1; i++) {
        if (i != 0 && src->arr[i] == src->arr[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < src->size; j++) {
            if (src->arr[i] == src->arr[j]) {
                dup_count++;
            }
        }
    }
    t_intarr *dst = (t_intarr*)malloc(0);
    dst->size = src->size - dup_count;
    dst->arr = malloc(dst->size);
    int d = dst->size - 1;
    bool is_dup;
    for (int i = src->size - 1; i >= 0; i--) {
        is_dup = false;
        for (int j = i - 1; j >= 0; j--) {
            if (src->arr[i] == src->arr[j]) {
                is_dup = true;
            }
        }
        if (!is_dup && d >= 0) {
            dst->arr[d] = src->arr[i];
            d--;
        }
    }
    return dst;
}
