#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strjoin(const char *s1, const char *s2);

/*
char *mx_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *mx_strnew(const int size) {
    char *tmp = (char*) malloc(size + 1);
    for (int i = 0; i <= size; i++){
        tmp[i] = '\0';
    }
    return tmp;
}

int mx_strlen(const char *s){
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

char *mx_strcat(char *s1, const char *s2) {
    int l = mx_strlen(s1);
    int i;
    for(i = 0; s2[i] != '\0'; i++) {
        s1[l + i] = s2[i];
    }
    s1[l + i] = '\0';
    return s1;
}

char *mx_strdup(const char *str) {
    char *tmp = mx_strnew(mx_strlen(str));
    mx_strcpy(tmp,str);   
    return tmp;
}

char *mx_strjoin(const char *s1, const char *s2) {
    int size = mx_strlen(s1) + mx_strlen(s2);
    char *result = mx_strnew(size);
    result = mx_strdup(s1);
    mx_strcat(result, s2);
    result[size] = '\0';
    return result;
}
*/
