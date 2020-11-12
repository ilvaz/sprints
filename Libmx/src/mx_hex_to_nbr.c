#include "libmx.h" 

bool mx_isalpha(int c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return true;
    }
    return false;
}

bool mx_isupper(int c) {
    if(c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

bool mx_isdigit(int c) {
    return (c>=48&&c<=57);
}

bool mx_islower(int c) {
    if(c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = 0;
    unsigned long sum = 0;
    for (int i = 0; hex[i]; i++)
        len++;
    for (int i = 0, j = 0; i <= len; i++) {
        if (mx_isalpha(hex[len - i])
            && (hex[len - i] >= 65 && hex[len - i] <= 70)) {
            sum += (hex[len - i] - 55) * mx_pow(16, j);
            j++;
        }
        else if (mx_isalpha(hex[len - i])
            && (hex[len - i] >= 97 && hex[len - i] <= 102)) {
            sum += (hex[len - i] - 87) * mx_pow(16, j);
            j++;
        }
        else if (mx_isdigit(hex[len - i])) {
            sum += (hex[len - i] - 48) * mx_pow(16, j);
            j++;
        }
    }
    return sum;
}
