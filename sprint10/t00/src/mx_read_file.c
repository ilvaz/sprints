#include "mx_read_file.h"

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
    if (argc != 2) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [file_path]\n");
        return 0;
    }
    char *filename = argv[1];
    char *content = malloc(1000);
    int file = open(filename, O_RDONLY);
    if (file == -1) {
        mx_printerr("error\n");
        return 0;
    }
    int bytes = read(file, content, 1000);
    if (bytes == -1) {
        mx_printerr("error\n");
        return 0;
    }
    if(close(file)) {
        mx_printerr("error\n");
        return 0;
    }
    printf("%s", content);
    return 0;
}
