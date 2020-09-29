#include <stdio.h>

int mx_strlen(const char *s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

char *mx_strcat(char *s1, const char *s2)
{
    char *begin = s1;
    while(*s1 != '\0') {
        printf("%s\n",s1);
        s1++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        printf("%s\n",s1);
        s1++;
        s2++;
    }
    *s1 = '\0';
    return begin;
}

int main(void) {
    char *src = "Hello ";
    src = mx_strcat(src,"Neo!");
    printf("%s\n", src);
    return 0;
}
