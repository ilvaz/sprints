#include "matrix.h"

char get_random_num(void) {
	return 33 + (rand() % 94);
}

char *randomstr(int size) {
    char *str = "`";
    for (int i = 0; i < size; i++) {
        str = mx_addchar(str, get_random_num());
    }
    return str;
}

int random_int(int b, int e) {
    return b + rand() % (e - b);
}
