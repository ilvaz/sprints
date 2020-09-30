#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);

void usage_error(char *programm_name);
void command_error(void);
