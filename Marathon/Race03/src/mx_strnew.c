#include "header.h"
  
char *mx_strnew(const int size) {
	char *mem = NULL;
	int i = 0;

	if (size < 0)
		return NULL;
	mem = (char *)malloc((size + 1) * sizeof(char));
	while (i < size) {
		mem[i] = '\0';
		i++;
	}
	mem[i] = '\0';
	return mem;
}
