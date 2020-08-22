#include <stdlib.h>


int *mx_copy_int_arr(const int *src, int size){
	if(size < 1 || src == 0)
		return NULL;

	int *p = malloc(size * sizeof *p);

	for (int i = 0; i < size; i++){
		p[i] = src[i];
	}

	return p;
}
