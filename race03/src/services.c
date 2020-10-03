#include "matrix.h"


t_str *mx_generate_str( int max_y, int max_x) {
    t_str *str = malloc(1);
    str->x = random_int(0,max_x);
    str->y = 0;
    str->s = randomstr(max_y - 1);
    str->i = 0;
    str->j = mx_strlen(str->s) - 1;
    str->end = random_int(3,max_y);
    str->is_end = false;
    str->next_y = 1;
    return str;
}

void mx_up_case(t_str *str) {
    str->f = 0;
    for (int k = str->j - str->i; k <= str->j; k++) {

        if (str->f == 0 && !str->is_end) {
            attron(COLOR_PAIR(2));
        } else {
            attron(COLOR_PAIR(1));
        }
        if (k >= 0) {
            move(str->y - str->f, str->x);
            addch(str->s[k]);
        }
        if (str->f <= str->end - 1) {
            str->f++;
        } else {
            break;
        }
    }
}

void mx_down_case(t_str *str, int max_y) {
    str->next_y = str->y + 1;

        if (str->next_y < max_y) {
            str->y++;
        }
        if (str->i < str->j && !str->is_end) {
            str->i++;
        } else if (str->i >= str->j) {
            str->is_end = true;
        }
        if (str->is_end) {
            str->i--;
            str->end--;
        }
        if(str->end < 0) {
            str->j = -20;
        }
}

t_str **mx_generate_matrix(int *n, int max_y, int max_x) {
    *n = random_int(max_x / 2, max_x - 1);
    t_str **m = malloc(*n + 1);
    for (int i = 0; i < *n; i++) {
        t_str *str = mx_generate_str(max_y, max_x);
        m[i] = str;
    }
    return m;
}
