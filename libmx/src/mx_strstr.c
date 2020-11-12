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

char *mx_strstr(const char *haystack, const char *needle) { 
    char *temphaystack = (char *)haystack; 
    char *tempneedle = (char *)needle; 
    if ((!haystack) || (!needle)) 
        return NULL; 
    if (!mx_strlen(needle)) 
        return temphaystack; 
    while (*temphaystack) { 
        if (!mx_strncmp(temphaystack, tempneedle, mx_strlen(tempneedle))) 
            return temphaystack; temphaystack++; 
    } 
    return NULL;
}
