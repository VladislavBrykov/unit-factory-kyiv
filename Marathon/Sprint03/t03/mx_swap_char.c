//#include <stdio.h>

void mx_swap_char(char *s1, char*s2) {
	char str = *s1;
	*s1 = *s2;
	*s2 = str;
}

//int main() {
//	char arr[5] = "Hello";
//	mx_swap_char(&arr[1], &arr[4]);
//	printf("%s\n", arr);
//	return 0;
//}
