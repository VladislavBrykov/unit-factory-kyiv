#include "libmx.h"

char *mx_strncpy(char *arr1, const char *arr2, int size)
{
	int i = 0;
	while(i < size) {
		arr1[i] = arr2[i];
		i++;
	}
	arr1[i] = '\0';
	return arr1;
}
