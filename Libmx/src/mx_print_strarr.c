#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
int num = 0;

	if(arr == NULL || delim == NULL)
		return;

	if (mx_strlen(delim) >= 0) {
		while((arr[num]) != NULL) {
			write(1, arr[num], mx_strlen(arr[num]));
			write(1, delim, mx_strlen(delim));
			num++;
		}
	}
	write(1, "\n", 1);
}

/*
int main() {
char *a[] = {"Hello", "Hell", NULL};
char *d = "";
mx_print_strarr(a, d);
}
*/
