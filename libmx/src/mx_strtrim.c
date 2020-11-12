#include "libmx.h" 

bool mx_is_space(char c) {
 	if(c == 32 || (c >= 9 && c <= 13)) return 1;
 	else return 0;
}

char *mx_strtrim(const char *str) { 
    int len = 0; 
    char *new = NULL; 
    while (mx_is_space(*str)) 
        str++; 
    len = mx_strlen(str); 
    while (mx_is_space(str[len - 1])) 
        len--; 
    new = mx_strndup(str, len); 
    return (char *)new;
}
