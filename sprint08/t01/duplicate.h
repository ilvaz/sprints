#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_intarr
{
	int *arr;
	int size;
}		    t_intarr;

int *mx_copy_int_arr(const int *src, int size);

t_intarr *mx_del_dup_sarr(t_intarr *src);
