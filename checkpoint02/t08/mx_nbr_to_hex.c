#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size) {
    char *tmp = (char*) malloc(size + 1);
    for (int i = 0; i <= size; i++){
        tmp[i] = '\0';
    }
    return tmp;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        return "0";
    }
    unsigned long tmp = nbr;
    int size = 1;
    while (tmp > 15){
        tmp /= 16;
        size++;
    }
    char *hex = mx_strnew(size);
    tmp = nbr;
    size--;
    while (tmp > 15) {
        int n = tmp % 16;
        if (n < 10) {
            hex[size] = n + '0';
            size--;
        } else if (n >= 10) {
            hex[size] = n + 87;
            size--;
        }
        tmp /= 16;
    }
    if (tmp < 10) {
        hex[0] = tmp + '0';
    } else if (tmp >= 10){
        hex[0] = tmp + 87;
    }
    return hex;
}
