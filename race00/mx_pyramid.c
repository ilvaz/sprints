#include <unistd.h>

void mx_printchar(char c);

void mx_multiprint(char c, int n);

void mx_printline(int n);

void mx_pyramid(int n);

void mx_multiprint(char c, int n) {
    for (int i = 0; i < n; i++)
        mx_printchar(c);
}

void mx_printline(int n) {
    mx_printchar('/');
    mx_multiprint('_', (n * 2) - 3);
    mx_printchar('\\');
    mx_printchar('|');
}

void mx_pyramid(int n) {
    if (n > 1){
        int is_space = 1;
        int distance = 1;
        for (int i = 0; i < n - 1; i++) {
            mx_multiprint(' ', n - 1 - i);
            if (i == 0) {
                mx_printchar('/');
                mx_printchar('\\');
            } 
            if (i != 0) {
                mx_printchar('/');
                mx_multiprint(' ', distance);
                mx_printchar('\\');
                distance += 2;
            }
            if (i < (n / 2) && i != 0) {
                mx_multiprint(' ', is_space);
                mx_printchar('\\');
                is_space += 1;
            }
            if (i >= (n / 2)) {
                is_space -= 1;
                mx_multiprint(' ', is_space);
                mx_printchar('|');
            }
            mx_printchar('\n');
        }
        mx_printline(n);
    }
    mx_printchar('\n');
}

