#include "libmx.h" 

int mx_strncmp(const char *s1, const char *s2, int n) {
    while (n && *s1 != '\0' && (*s1 == *s2)) {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0) {
        return 0;
    }
    else {
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    }
}

int mx_get_substr_index(const char *str, const char *sub) { 
    int index = 0; 
    int sublen = 0; 
    if (sub && str) { 
        sublen = mx_strlen(sub); 
        while (*str) { 
            if (mx_strncmp(str, sub, sublen) == 0) 
                return index; 
            index++; 
            str++; 
        } 
        return -1; 
    }
    return -2;
 }
