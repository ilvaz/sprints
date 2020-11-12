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

char *mx_replace_substr(const char *str, const char *sub, const char *replace) { 
    int sum = mx_strlen(replace) - mx_strlen(sub); 
    int len = mx_strlen(str) + mx_count_substr(str, sub) * sum; 
    char *memory = mx_strnew(len);  
    if (!str || !sub || !replace || mx_strlen(str) <= mx_strlen(sub))  
        return NULL; 
    else {  
        for (int i = 0; i < len; i++, str++) {   
            if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub))) {    
                str += mx_strlen(sub);    
                for (int j = 0; j < mx_strlen(replace); i++, j++)     
                    memory[i] = replace[j];   
            }   
            memory[i] = *str;  
        }  
        return memory; 
    }
}
