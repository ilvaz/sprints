#include "get_address.h"

char *mx_get_addres(void *p);

char *mx_get_addres(void *p) {
    char *tmp = mx_nbr_to_hex((unsigned long)&p);
    char *result = mx_strnew(mx_strlen(tmp) + 2);
    result[0] = '0';
    result[1] = 'x';
    result += 2;
    mx_strcpy(result,tmp);
    result -= 2;
    return result;
}

