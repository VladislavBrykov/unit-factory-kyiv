//#include <stdio.h>

int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);

void mx_str_reverse(char *s) {
	int lenght = mx_strlen(s) - 1; // -1 in swap_char dell \0
	for (int i = 0; i <= lenght / 2; i++)	//middle 
	mx_swap_char(&s[i], &s[lenght -i]);
}

//int main() {
//	char arr1[4] = "abc";
//	printf("%s\n", arr1);
//	mx_str_reverse(arr1);
//	printf("%s\n", arr1);
//}
