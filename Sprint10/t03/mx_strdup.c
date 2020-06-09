#include "file_to_str.h"

char *mx_strdup(const char *str) {
	int lenght = mx_strlen(str);
	char *arr = mx_strnew(lenght);
	mx_strcpy(arr, str);
	return arr;
}

/*int main() {
	char str[6] = "Hello";
	printf("%s\n", mx_strdup(str));
	return 0;
}

strcpy - копирует данные из строки, на которую указывает аргумент 
source, в строку, на которую указывает аргумент destination, пока не 
встретится символ конца строки (нулевой символ). Копирование производится 
вместе с символом конца строки.

strlen - длина строки

strnew - выделяет память для строки определенного размера и одного 
дополнительного байта для '\0'
*/
