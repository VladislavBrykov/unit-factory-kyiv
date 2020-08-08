#include "mx_wc.h"

char *mx_strnew(const int size) {
	char *arr = malloc(size * sizeof(*arr) + 1);

	if(arr != NULL && size > 0) {
		for(int i = 0; i <= size+1; i++) 
					arr[i] = '\0';
		return arr;
	}
	return NULL;
}

/*int main()
{
	printf("%s\n", mx_strnew(10));
	return 0;
}

Выделили память под указатель на массив arr. Если память выделена arr != NULL
заполняем выделеную память. 

malloc(size * sizeof(*arr) + 1) - размер умножаем тип char 1bt, int уже 4 будет

size + 1 - указана в задании, выделить память size и добавить еще один символ онца строки.
Если память не выделена malloc*/
