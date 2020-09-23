#include <stdbool.h>

void mx_printchar(char c);

void mx_printint(int n);

void mx_printint(int n) {
    char s[20];
    int size = 0;
    bool is_negative = false;
    
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    
    if (n < 0) {
        is_negative = true;
        n *= -1;
    }
    
    while (n > 0) {
        s[size] = n % 10 + '0';
        n -= n % 10;
        n /= 10;
        size++;
    }
    if (is_negative){
        mx_printchar('-');
    }
    for (size -= 1; size >= 0; size--){
        mx_printchar(s[size]);
    }
    mx_printchar('\n');}
