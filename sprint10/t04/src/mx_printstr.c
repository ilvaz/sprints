#include <unistd.h>

int mx_strlen(char *s);

void mx_printstr(char *s) {
	write(1, s, mx_strlen(s));
}

