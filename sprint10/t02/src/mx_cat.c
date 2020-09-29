#include "mx_cat.h"
#include <errno.h>

int mx_strlen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void mx_printstr(char *s) {
    write(1, s, mx_strlen(s));
}

void mx_printerr(char *s) {
    write(2, s, mx_strlen(s));
}

int main(int argc, char **argv) {
    if (argc == 1) {
        mx_printerr("hello\n");
        mx_printstr("hello\n");
        exit(1);
    }
    char *filename = argv[1];
    char content;
    int file = open(filename, O_RDONLY);
    if (errno == ENOENT){
        mx_printerr(argv[0]);
        mx_printerr(": ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        exit(1);
    }
    /*if (file == -1) {
        mx_printerr("error\n");
        exit(1);
    }*/
    while (read(file, &content, 1) > 0) {
        write(1, &content, 1);
    }

    if(close(file)) {
        mx_printerr("error\n");
        exit(1);
    }
    
    return 0;
}
