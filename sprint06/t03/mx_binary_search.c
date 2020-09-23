#include <stdbool.h>

int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left =  0;
    int right = size;
    int midd = 0;
    bool flag = false;
    while (left <= right && flag != true) {
        midd = (left + right) / 2;
        if  (mx_strcmp(s, arr[midd]) == 0){
            flag = true;
        }
        if (mx_strcmp(s, arr[midd]) < 0) {
            right = midd - 1;
        } else if (mx_strcmp(s, arr[midd]) > 0) {
            left = midd + 1;
        }
        count[0]++;
    }
    if (flag) {
        return midd;
    } else {
        return -1;
    }
        
}

