#include <stdbool.h>

int mx_strcmp(const char *s1, const char *s2);

int mx_bubble_sort(char **arr, int size);

int mx_bubble_sort(char **arr, int size) {
    int num_swap = 0;
    bool change;
    do {
        for (int i = 0; i < size - 1; i++) {
            change = false;
            if (mx_strcmp(arr[i], arr[i + 1]) >= 0) {
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                change = true;
                num_swap++;
            }
        }
    } while (change);
    return num_swap;
}

