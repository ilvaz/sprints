#include <ncurses.h>
#include "locale.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DELAY 100000


typedef struct s_str
{
    char *s;
    int x;
    int y;
    int next_y;
    int i;
    int j;
    int end;
    bool is_end;
    int f;
}               t_str;

char *mx_addchar(char *s, char c);
char get_random_num(void);
char *randomstr(int size);
int random_int(int b, int e);

t_str *mx_generate_str(int max_y, int max_x);
void mx_up_case(t_str *str);
void mx_down_case(t_str *str, int max_y);
t_str **mx_generate_matrix(int *n, int max_y, int max_x);

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
