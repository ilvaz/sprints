#include <stdio.h>

int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) {
    int l = mx_strlen(s1);
    int i;
    for(i = 0; s2[i] != '\0'; i++) {
        s1[l + i] = s2[i];
    }
    s1[l + i] = '\0';
    return s1;
}
