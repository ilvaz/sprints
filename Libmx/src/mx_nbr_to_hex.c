#include "libmx.h" 

static void perevod(unsigned long nbr, char *result) {
    unsigned long num = 0;
    int j = 0;
    while (nbr) {
        num = nbr % 16;
        if (num < 10) {
            result[j] = num + 48;
            j++;
        }
        else if (num <= 16) {
            result[j] = num + 87;
            j++;
        }
        nbr /= 16;
    }
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *result;
    unsigned long temp = nbr;
    unsigned long num = 0;
    unsigned long size = 0;
    while (temp) {
        num = temp % 16;
        if (num >= 0 && num <= 16)
            size++;
        temp /= 16;
    }
    result = mx_strnew(size);
    perevod(nbr, result);
    mx_str_reverse(result);
    return result;
}
