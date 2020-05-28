#include <stdio.h>

void *mx_strncpy(char *arr1, const char *arr2, int size)
{
	int i = 0;
	while(i < size) {
		arr1[i] = arr2[i];
		i++;
	}
	arr1[i] = '\0';
	return arr1;
}

int main() {
	int size = 6;
	char arr1[size];
	const char arr2[] = "Hello";
	mx_strncpy(arr1, arr2, size);
	printf("%s\n", arr1);
}

