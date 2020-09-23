#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c);

void mx_multiprint(char c, int n);

void mx_cube(int n);

void mx_printline(int n);

void mx_print_topedge(int n, int edge);

void mx_multiprint(char c, int n){
    for (int i = 0; i < n; i++)
        mx_printchar(c);
}

void mx_printline(int n){
    mx_printchar('+');
    mx_multiprint('-', n*2);
    mx_printchar('+');
}

void mx_print_topedge(int n, int edge){
    mx_multiprint(' ', (n / 2) - edge);
    mx_printchar('/');
    mx_multiprint(' ', n * 2);
    mx_printchar('/');
    edge++;
}

void mx_cube(int n) {
        if (n > 1) {
                int height = n + 2 + (n / 2);
                int vertical = n;
                int edge = 0;
                for (int i = 0; i < height; i++) {
                        if (i == height - 1){
                            mx_printline(n);
                        }
                        if (i == 0) {
                            mx_multiprint(' ', (n / 2) + 1);
                            mx_printline(n); 
                            mx_printchar('\n');
                        }
                        if (i < (n / 2)) {
                            mx_print_topedge(n, edge);
                            edge++;
                        }
                        if (i == (n / 2)) {
                            mx_printline(n);
                        }
                        if (i > (n / 2) && i != height - 1) {
                            mx_printchar('|');
                            mx_multiprint(' ', n * 2);
                            mx_printchar('|');
                        }
                        if (vertical == 0) {
                            mx_multiprint(' ', n / 2);
                            mx_printchar('+');
                            vertical--;
                        }
                        if (i < n && vertical > 0) {
                            if (i < n / 2){
                                mx_multiprint(' ', i);
                            }else {
                                mx_multiprint(' ', n / 2);
                            }
                            mx_printchar('|');
                            vertical--;
                        }
                        if (i > n && i != height - 1) {
                            mx_multiprint(' ', edge - 1);
                            mx_printchar('/');
                            edge--;
                        }
                    mx_printchar('\n');
                }
        }    
}

