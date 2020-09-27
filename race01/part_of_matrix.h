#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_init
{
    char *name;
    int number;
    bool is_unknown;
    int rank;
}                   t_init;

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
char *mx_strnew(const int size);

