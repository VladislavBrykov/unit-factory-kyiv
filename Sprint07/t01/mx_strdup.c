#include <stdlib.h>
#include <stdio.h>

char *mx_strcpy(char *dst, const char *src) {
	int count = 0;
	while (src[count]) {
		dst[count] = src[count];
		count++; }
	dst[count] = '\0';
	return dst;
}

int mx_strlen(const char *s)
{
	int i = 0;
	while(s[i]) {
		i++;
	}
	return i;
}

char *mx_strnew(const char size) {
	char *arr = malloc(size + 1);

	if(arr != NULL && size > 0) {
		for(int i = 0; i <= size+1; i++) 
					arr[i] = '\0';
		return arr;
	}
	return NULL;
}

char *mx_strdup(const char *str) {
	int lenght = mx_strlen(str);
	char *arr = mx_strnew(lenght);
	mx_strcpy(arr, str);
	return arr;
}

int main() {
	char str[6] = "Hello";
	printf("%s\n", mx_strdup(str));
	return 0;
}

/*strcpy - копирует данные из строки, на которую указывает аргумент 
source, в строку, на которую указывает аргумент destination, пока не 
встретится символ конца строки (нулевой символ). Копирование производится 
вместе с символом конца строки.

strlen - длина строки

strnew - выделяет память для строки определенного размера и одного 
дополнительного байта для '\0'
*/

