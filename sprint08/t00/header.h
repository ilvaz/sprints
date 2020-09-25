#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(char *s);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(char *s);
int mx_strcmp(const char *s1, const char *s2);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char *str);
