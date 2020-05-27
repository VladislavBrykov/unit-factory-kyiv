#include <stdio.h>

char *mx_strcpy(char *dst, const char *src) {
	int count = 0;
	while (src[count]) {
		dst[count] = src[count];
		count++; }
	dst[count] = '\0';
	return dst;
}

//int main()
//{
//	char a[6] = "Hello";
//	char b[6];
//	mx_strcpy(b, a);
//	printf("%s\n", b);
//	return 0;
//} 
