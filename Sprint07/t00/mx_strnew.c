#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const char size) {
	char *arr = malloc(size + 1);

	if(arr != NULL && size > 0) {
		for(int i = 0; i <= size+1; i++) 
					arr[i] = '\0';
		return arr;
	}
	return NULL;
}

int main()
{
	printf("%s\n", mx_strnew(10));
	return 0;
}

/*Выделили память под указатель на массив arr. Если память выделена arr != NULL
заполняем выделеную память. 
size + 1 - указана в задании, выделить память size и добавить еще один символ онца строки.
Если память не выделена malloc*/
