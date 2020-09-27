#include "part_of_matrix.h"

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

int mx_strlen(const char *s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int mx_strcmp(const char *s1, const char *s2) {
    int i = 0;
    int result = 0;
    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] == s2[i]){
            i++;
        } else {
            result = s1[i] - s2[i];
            break;
        }
    }
    return result;
}

bool mx_isspace(char c) {
	if (c == ' ') return true;
	else return false;
}

bool mx_isdigit(int c) {
	if (c > 47 && c < 58) {
		return true;
	} else {
		return false;
	}
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

char *mx_strnew(const int size) {
    char *tmp = (char*) malloc(size + 1);
    for (int i = 0; i <= size; i++){
        tmp[i] = '\0';
    }
    return tmp;
}

