#include <unistd.h>

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

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        write(1, "\n", 1);
    }
    return 0;
}
