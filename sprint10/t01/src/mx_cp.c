#include "mx_cp.h"
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
    if (argc != 3) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [source_file] [destination_file]\n");
        return 0;
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];
    char content;
    int file1 = open(filename1, O_RDONLY);
    if (errno == ENOENT) {
        mx_printerr(argv[0]);
        mx_printerr(": ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        exit(1);
    }
    int file2 = open(filename2, O_WRONLY|O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
    if (file2 == -1 ) {
        mx_printerr("error\n");
        exit(1);
    }
    while (read(file1, &content, 1) > 0) {
        write(file2, &content, 1);
    }
    if(close(file1) || close(file2)) {
        mx_printerr("error\n");
        exit(1);
    }
    return 0;
}
