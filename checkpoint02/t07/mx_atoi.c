#include <stdbool.h>

bool mx_isdigit(int c) {
	if (c > 47 && c < 58) {
		return true;
	} else {
		return false;
	}
}

bool mx_isspace(char c) {
	if (c == ' ') return true;
	else return false;
}

int mx_atoi(const char *str) {
    int result = 0;
    int i = 0;
    bool is_negative = false;
    
    if (str[0] == '-') {
        is_negative = true;
        i++;
    }

    if (str[0] == '+') {
        i++;
    }
    
    while (str[i] != '\0') {
        if (!mx_isdigit(str[i])) {
            return 0;
        }
        int tmp = (int)str[i] - 48;
        if (i == 0) {
            result += tmp;
        } else {
            result *= 10;
            result += tmp;
        }
        i++;
    }
    
    if (is_negative) {
        result *= -1;
    }
    
    return result;
}
