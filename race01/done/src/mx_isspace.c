#include <stdbool.h>

bool mx_isspace(char);

bool mx_isspace(char c) {
	if (c == ' ') return true;
	else return false;
}
