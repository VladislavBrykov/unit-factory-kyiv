#include <stdio.h>
#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
	if(size < 1 || src == NULL)
		return NULL;

	int *p = malloc(size * sizeof(*p));

	for (int i = 0; i < size; i++){
		p[i] = src[i];
	}

	return p;
}

int main() {
int arr1[] = {1, 2, 3};
int *result = mx_copy_int_arr(arr1, 3);

for(int i = 0; i < 3; i++)
	printf("%d", result[i]);
}

/*
DESCRIPTION
Create a function that copies an array of integers to a new array.
RETURN
• returns the pointer to the first element
• returns NULL if the array src does not exist or copying fails
*/
