#include "hex_to_nbr.h"

unsigned long mx_hex_to_nbr(const char *hex); 

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long m = 1;
    unsigned long result = 0;
    int i = 0;
    while (hex[i] != '\0') {
        if (!mx_isdigit(hex[i]) && !mx_isalpha(hex[i])) {
            return 0;
        }
        i++;
    }
    i--;
    while (i >= 0) {
        if (mx_isdigit(hex[i])){
            result += (hex[i] - '0') * m;
        } else if (mx_isalpha(hex[i])) {
            if (mx_isupper(hex[i])) {
                if (hex[i] < 71) {
                    result += (hex[i] - 55) * m;
                } else {
                    return 0;
                }
            } else if (mx_islower(hex[i])) {
                if (hex[i] < 103) {
                    result += (hex[i] - 87) * m;
                } else {
                    return 0;
                }
            }
        }
        m *= 16;
        i--;
    }
    return result;
}

