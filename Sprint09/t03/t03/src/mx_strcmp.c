#include "header.h"

int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;
	int j = 0;
	while(s1[i] == s2[j]) {
		i++;
		j++;
	}
	return(s1[i] - s2[j]);
}

//int main() {
//	int result;
//	char str1[5] = "Hello";
//	char str2[6] = "Halloy";
//	printf("my: ");
//	printf("%d\n", mx_strcmp(str1, str2));
//	printf("strcmp: ");
//	result = strcmp(str1, str2);
//	printf("%d\n", result);
//	return 0;
//}

