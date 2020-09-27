#include "part_of_matrix.h"

char *mx_del_space (char *s) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if(!mx_isspace(s[i])) {
            j++;
        }
        i++;
    }
    char *result = mx_strnew(j);
    i = 0;
    j = 0;
    while (s[i] != '\0') {
        if(!mx_isspace(s[i])) {
            result[j] = s[i];
            j++;
        }
        i++;
    }
    return result;
}

bool mx_is_strdig(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if(!mx_isdigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int mx_rank(char *s) {
    return mx_strlen(s);
}

int mx_int_rank(int n) {
    if (n == 0) {
        return 1;
    }
    int i = 0;
    while (n > 0) {
        n /= 10;
        i++;
    }
    return i;
}

void mx_substraction(t_init *data) {
    int operand1;
    int operand2;
    int result;
    if (data[0].is_unknown && data[2].is_unknown) {
        operand2 = data[1].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand1 = i;
        }
        result = operand1 - operand2;
        while (mx_int_rank(operand1) == data[0].rank) {
            if (mx_int_rank(result) == data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" - ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');

            }
            operand1++;
            result = operand1 - operand2;
        }
    } else if (data[1].is_unknown && data[2].is_unknown) {
        operand1 = data[0].number;
        for (int i = 1; mx_int_rank(i) <= data[1].rank + 1; i *= 10) {
            operand2 = i;
        }
        operand2--;
        result = operand1 - operand2;
        while (mx_int_rank(operand2) >= data[1].rank) {
            if (mx_int_rank(result) == data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" - ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2--;
            result = operand1 - operand2;
        }
    } else if (data[0].is_unknown && data[1].is_unknown) {
        result = data[2].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand1 = i;
        }
        for (int i = 1; mx_int_rank(i) <= data[1].rank + 1; i *= 10) {
            operand2 = i;
        }
        operand2--;
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp2 = operand2;
            int tmp_res = operand1 - tmp2;
            while (mx_int_rank(tmp2) >= data[1].rank) {
                if (tmp_res == result) {
                    mx_printint(operand1);
                    mx_printstr(" - ");
                    mx_printint(tmp2);
                    mx_printstr(" = ");
                    mx_printint(result);
                    mx_printchar('\n');
                }
                tmp2--;
                tmp_res = operand1 - tmp2;
            }
            operand1++;
        }
    } else if (data[0].is_unknown) {
        operand2 = data[1].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand1 = i;
        } 
        result = data[2].number;
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp = operand1 - operand2;
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" - ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            tmp = operand1 - operand2;
        }
        
    } else if (data[1].is_unknown) {
        operand1 = data[0].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank + 1; i *= 10) {
            operand2 = i;
        }
        operand2--;
        result = data[2].number;
        int tmp = operand1 - operand2;
        while (mx_int_rank(operand2) >= data[1].rank) {
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" - ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2--;
            tmp = operand1 - operand2;
        }
    } else if(data[2].is_unknown) {
        operand1 = data[0].number;
        operand2 = data[1].number;
        result = operand1 - operand2;
        if (mx_int_rank(result) == data[2].rank) {
            mx_printint(operand1);
            mx_printstr(" - ");
            mx_printint(operand2);
            mx_printstr(" = ");
            mx_printint(result);
            mx_printchar('\n');
        }
    }
}

void mx_addition(t_init *data) {
    int operand1;
    int operand2;
    int result;
    if (data[0].is_unknown && data[2].is_unknown) {
        operand2 = data[1].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand1 = i;
        }
        result = operand1 + operand2;
        while (mx_int_rank(operand1) == data[0].rank) {
            if (mx_int_rank(result) == data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" + ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            result = operand1 + operand2;
        }
    } else if (data[1].is_unknown && data[2].is_unknown) {
        operand1 = data[0].number;
        for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
            operand2 = i;
        }
        result = operand1 + operand2;
        while (mx_int_rank(operand2) == data[1].rank) {
            if (mx_int_rank(result) == data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" + ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2++;
            result = operand1 + operand2;
        }
    } else if (data[0].is_unknown && data[1].is_unknown) {
        result = data[2].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand1 = i;
        }
        for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
            operand2 = i;
        }
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp2 = operand2;
            int tmp_res = operand1 + tmp2;
            while (mx_int_rank(tmp2) >= data[1].rank) {
                if (tmp_res == result) {
                    mx_printint(operand1);
                    mx_printstr(" + ");
                    mx_printint(tmp2);
                    mx_printstr(" = ");
                    mx_printint(result);
                    mx_printchar('\n');
                }
                tmp2++;
                tmp_res = operand1 + tmp2;
            }
            operand1++;
        }
    } else if (data[0].is_unknown) {
        operand2 = data[1].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand1 = i;
        } 
        result = data[2].number;
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp = operand1 + operand2;
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" + ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            tmp = operand1 + operand2;
        }
        
    } else if (data[1].is_unknown) {
        operand1 = data[0].number;
        for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
            operand2 = i;
        }
        result = data[2].number;
        int tmp = operand1 + operand2;
        while (mx_int_rank(operand2) >= data[1].rank) {
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" + ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2++;
            tmp = operand1 + operand2;
        }
    } else if(data[2].is_unknown) {
        operand1 = data[0].number;
        operand2 = data[1].number;
        result = operand1 + operand2;
        if (mx_int_rank(result) == data[2].rank) {
            mx_printint(operand1);
            mx_printstr(" + ");
            mx_printint(operand2);
            mx_printstr(" = ");
            mx_printint(result);
            mx_printchar('\n');
        }
    }
}

void mx_multiplication(t_init *data) {
    int operand1;
    int operand2;
    int result;
    if (data[0].is_unknown && data[2].is_unknown) {
        operand2 = data[1].number;
        if (data[0].rank == 1) {
            operand1 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
                operand1 = i;
            }
        }
        result = operand1 * operand2;
        while (mx_int_rank(operand1) == data[0].rank) {
            if (mx_int_rank(result) <= data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" * ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            result = operand1 * operand2;
        }
    } else if (data[1].is_unknown && data[2].is_unknown) {
        operand1 = data[0].number;
        if (data[1].rank == 1) {
            operand2 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
                operand2 = i;
            }
        }
        result = operand1 * operand2;
        while (mx_int_rank(operand2) == data[1].rank) {
            if (mx_int_rank(result) <= data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" * ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2++;
            result = operand1 * operand2;
        }
    } else if (data[0].is_unknown && data[1].is_unknown) {
        result = data[2].number;
        if (data[0].rank == 1) {
            operand1 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
                operand1 = i;
            }
        }
        if (data[1].rank == 1) {
            operand2 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
                operand2 = i;
            }
        }
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp2 = operand2;
            int tmp_res = operand1 * tmp2;
            while (mx_int_rank(tmp2) >= data[1].rank) {
                if (tmp_res == result) {
                    mx_printint(operand1);
                    mx_printstr(" * ");
                    mx_printint(tmp2);
                    mx_printstr(" = ");
                    mx_printint(result);
                    mx_printchar('\n');
                }
                tmp2++;
                tmp_res = operand1 * tmp2;
            }
            operand1++;
        }
    } else if (data[0].is_unknown) {
        operand2 = data[1].number;
        if (data[0].rank == 1) {
            operand1 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
                operand1 = i;
            }
        }
        result = data[2].number;
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp = operand1 * operand2;
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" * ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            tmp = operand1 * operand2;
        }
        
    } else if (data[1].is_unknown) {
        operand1 = data[0].number;
        if (data[1].rank == 1) {
            operand2 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
                operand2 = i;
            }
        }
        result = data[2].number;
        int tmp = operand1 * operand2;
        while (mx_int_rank(operand2) >= data[1].rank) {
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" * ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2++;
            tmp = operand1 * operand2;
        }
    } else if(data[2].is_unknown) {
        operand1 = data[0].number;
        operand2 = data[1].number;
        result = operand1 * operand2;
        if (mx_int_rank(result) == data[2].rank) {
            mx_printint(operand1);
            mx_printstr(" * ");
            mx_printint(operand2);
            mx_printstr(" = ");
            mx_printint(result);
            mx_printchar('\n');
        }
    }
}

void mx_division(t_init *data) {
    int operand1;
    int operand2;
    int result;
    if (data[0].is_unknown && data[2].is_unknown) {
        operand2 = data[1].number;
        if (operand2 == 0) {
            exit(0);
        }
        if (data[0].rank == 1) {
            operand1 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
                operand1 = i;
            }
        }
        result = operand1 / operand2;
        while (mx_int_rank(operand1) == data[0].rank) {
            if (mx_int_rank(result) <= data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" / ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            result = operand1 / operand2;
        }
    } else if (data[1].is_unknown && data[2].is_unknown) {
        operand1 = data[0].number;
        if (data[1].rank == 1) {
            operand2 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
                operand2 = i;
            }
        }
        result = operand1 / operand2;
        while (mx_int_rank(operand2) == data[1].rank) {
            if (mx_int_rank(result) <= data[2].rank) {
                mx_printint(operand1);
                mx_printstr(" / ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2++;
            result = operand1 / operand2;
        }
    } else if (data[0].is_unknown && data[1].is_unknown) {
        result = data[2].number;
        if (data[0].rank == 1) {
            operand1 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
                operand1 = i;
            }
        }
        
        for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
            operand2 = i;
        }
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp2 = operand2;
            int tmp_res = operand1 / tmp2;
            while (mx_int_rank(tmp2) >= data[1].rank) {
                if (tmp_res == result) {
                    mx_printint(operand1);
                    mx_printstr(" / ");
                    mx_printint(tmp2);
                    mx_printstr(" = ");
                    mx_printint(result);
                    mx_printchar('\n');
                }
                tmp2++;
                tmp_res = operand1 / tmp2;
            }
            operand1++;
        }
    } else if (data[0].is_unknown) {
        operand2 = data[1].number;
        if (operand2 == 0) {
            exit(0);
        }
        if (data[0].rank == 1) {
            operand1 = 0;
        } else {
            for (int i = 1; mx_int_rank(i) <= data[0].rank; i *= 10) {
                operand1 = i;
            }
        }
        result = data[2].number;
        while (mx_int_rank(operand1) == data[0].rank) {
            int tmp = operand1 / operand2;
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" / ");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand1++;
            tmp = operand1 / operand2;
        }
        
    } else if (data[1].is_unknown) {
        operand1 = data[0].number;
        for (int i = 1; mx_int_rank(i) <= data[1].rank; i *= 10) {
            operand2 = i;
        }
        result = data[2].number;
        int tmp = operand1 / operand2;
        while (mx_int_rank(operand2) == data[1].rank) {
            if (tmp == result) {
                mx_printint(operand1);
                mx_printstr(" /");
                mx_printint(operand2);
                mx_printstr(" = ");
                mx_printint(result);
                mx_printchar('\n');
            }
            operand2++;
            tmp = operand1 / operand2;
        }
    } else if(data[2].is_unknown) {
        operand1 = data[0].number;
        operand2 = data[1].number;
        if (operand2 == 0) {
            exit(0);
        }
        result = operand1 / operand2;
        if (mx_int_rank(result) == data[2].rank) {
            mx_printint(operand1);
            mx_printstr(" / ");
            mx_printint(operand2);
            mx_printstr(" = ");
            mx_printint(result);
            mx_printchar('\n');
        }
    }
}

void mx_separate(char **argv) {
    t_init operand1;
    operand1.name = argv[0];
    operand1.rank = mx_rank(operand1.name);
    
    char *operation = argv[1];
    
    t_init operand2;
    operand2.name = argv[2];
    operand2.rank = mx_rank(operand2.name);
    
    t_init result;
    result.name = argv[3];
    result.rank = mx_rank(result.name);
    
    if (mx_is_strdig(operand1.name)) {
        operand1.number = mx_atoi(operand1.name);
        operand1.is_unknown = false;
    } else {
        operand1.is_unknown = true;
    }
    if (mx_is_strdig(operand2.name)) {
        operand2.number = mx_atoi(operand2.name);
        operand2.is_unknown = false;
    } else {
        operand2.is_unknown = true;
    }
    if (mx_is_strdig(result.name)) {
        result.number = mx_atoi(result.name);
        result.is_unknown = false;
    } else {
        result.is_unknown = true;
    }
    
    t_init init_data[] = {operand1, operand2, result};
    
    if (mx_strcmp(operation, "-") == 0) {
        mx_substraction(init_data);
    } else if (mx_strcmp(operation, "+") == 0) {
        mx_addition(init_data);
    } else if (mx_strcmp(operation, "*") == 0) {
        mx_multiplication(init_data);
    } else if (mx_strcmp(operation, "/") == 0) {
        mx_division(init_data);
    } 
}

bool mx_is_strque(char *s) {
    int i = 0; 
    while (s[i] != '\0') {
        if (s[i] != '?') {
            return false;
        }
        i++;
    }
    return true;
}

void mx_op_nd_err(char *s) {
    if (!mx_is_strdig(s) && !mx_is_strque(s)) {
        mx_printstr("Invalid operand: ");
        mx_printstr(s);
        mx_printchar('\n');
        exit(0);
    }
}

void mx_op_tion_err(char *s) {
    if (mx_strlen(s) != 1 && mx_strcmp(s, "+") != 0 && mx_strcmp(s, "-") != 0 && mx_strcmp(s, "*") != 0 && mx_strcmp(s, "/") != 0) {
        mx_printstr("Invalid operation: ");
        mx_printstr(s);
        mx_printchar('\n');
        exit(0);
    }
}

void mx_review(int argc, char **argv) {
    
    if (argc != 5) {
        mx_printstr("usage: ");
        mx_printstr(argv[0]);
        mx_printstr(" [operand1] [operation] [operand2] [result]\n");
        exit(0);
    }
    
    char *source[argc - 1];
    for (int i = 1; i < argc; i++) {
        source[i - 1] = mx_del_space(argv[i]);
    }
    mx_op_tion_err(source[1]);
    mx_op_nd_err(source[0]);
    mx_op_nd_err(source[2]);
    mx_op_nd_err(source[3]);
    
    mx_separate(source);
}

int main(int argc, char **argv)
{
    mx_review(argc, argv);
    return 0;
}

