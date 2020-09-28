#include <unistd.h>
#include <stdbool.h>

void mx_printchar(char s) {
    write(1, &s, 1);
}

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
}


int main(int argc, char **argv) {
    mx_printstr(argv[0]);
    write(1, "\n", 1);
    mx_printint(argc);
    write(1, "\n", 1);
    return 0;
}
