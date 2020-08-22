/*
Create a function that:
• takes a pointer to a string
• frees the string's memory with free
• sets the string to NULL
*/



#include <stdlib.h>
#include <stdio.h>

void mx_strdel(char **str) {	
	if(str && *str) { 
		free(*str);		
		*str = NULL;		
	}
}

/*int main()
{
	char *s1 = malloc(5 * sizeof(*s1));
		if(s1 != NULL) {
		for(int i = 0; i <= 5; i++) 
					s1[i] = '0';
		printf("%s\n", s1);

	char **s2 = &s1;
	mx_strdel(s2);
		printf("%s\n", *s2);
	return 0;
	}
}

Для проверки выделяю память под указатель, заполняю ее нулями и печатаю.
Закидываю в функцию, где память очищается и значение присваивается NULL.
Снова печатаю - выводит NULL,
*/

