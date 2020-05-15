#include <stdio.h>

void mx_deref_pointer(char ******str)
{
	*****str = "Hello";
}

int main()
{
	char *str;
	char **str1 = &str;
	char ***str2 = &str1;
	char ****str3 = &str2;
	char *****str4 = &str3;
	char ******str5 = &str4;
	mx_deref_pointer(str5);
	printf("%s\n", str);
	return 0;
}
