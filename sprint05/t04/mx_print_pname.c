#include <stdio.h>

int mx_strlen(char *s);

void mx_printstr(char *s);

void mx_printchar(char c);

char *mx_strchr(const char *s, int c);

int main(int argc, char **argv) {
    char *p;
    char *tmp = mx_strchr(argv[argc - argc], '/');
    while (tmp != NULL){
        p = tmp + 1;
        tmp = mx_strchr(p, '/');
    }
    mx_printstr(p);
    mx_printchar('\n');
    return 0;
}
