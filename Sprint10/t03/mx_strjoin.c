/*DESCRIPTION
Create a function that:
• concatenates strings s1 and s2 into a new string
• terminates the new string with '\0'
RETURN
• returns the string as a result of concatenation s1 and s2
• returns the new copy of non-NULL parameter if one and only one of the parameters is
NULL
• returns NULL if the concatenation fails
*/

#include "file_to_str.h"



/*function*/

char *mx_strjoin(char const *s1, char const *s2) {
	if(s1 != NULL && s2 != NULL) {
	char *dubl_s1 = mx_strdup(s1);
	char *s1s2 = mx_strcat_new(dubl_s1, s2);
	return s1s2;
	}
	else if(s1 == NULL && s2 != NULL) {
		char *dubl_s2 = mx_strdup(s2);
		return dubl_s2;
	}
	else if(s2 == NULL && s1 != NULL) {
		char *dubl_s1 = mx_strdup(s1);
		return dubl_s1;
	}
	return NULL;
}

/*int main()
{
const char *str1 = "this";
const char *str2 = "dodge ";
const char *str3 = NULL;
printf("%s\n", mx_strjoin(str2, str1)); //returns "dodge this"
printf("%s\n", mx_strjoin(str1, str3)); //returns "this"
printf("%s\n", mx_strjoin(str3, str3)); //returns NULL
return 0;
}


---strnew - создание новой строки размера сайз
---strlen - длина строки
---strcpy копирует данные из строки, на которую указывает аргумент source, 
в строку, на которую указывает аргумент destination, пока не встретится 
символ конца строки (нулевой символ). Копирование производится вместе с
символом конца строки. 
---strdup - Функция strdup дублирует строку, на которую указывает аргумент str. 
Память под дубликат строки выделяется с помощью функции malloc
---strcat - оединяет в цепочку) строку str1 и копию строки str2
*/

