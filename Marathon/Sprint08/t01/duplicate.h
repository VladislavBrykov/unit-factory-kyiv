#ifndef DUPLICATE_H
#define DUPLICATE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int *mx_copy_int_arr(const int *src, int size);
int *mx_del_dup_sarr(int *src, int src_size, int *dst_size);

typedef struct s_intarr 
{
	int *arr;
	int size;
}		t_intarr;

#endif
