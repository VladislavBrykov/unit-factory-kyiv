#include "file_to_str.h"

char *mx_strcat_new(char *s1, const char *s2) {
	int lenght1 = mx_strlen(s1);
	int i = 0;
	while(s2[i]) {
		s1[lenght1] = s2[i];
		lenght1++;
		i++;
		}
	s1[lenght1] = '\0';
	return s1;
}

//int main() {
//	char s1[5] = "Hell";
//	const char s2[6] = "Hello";
//	printf("%s\n", mx_strcat_new(s1, s2);
//}
		
