#include "file_to_str.h"

int mx_strlen(const char *s) {
	int i = 0;
	while(s[i])
		i++;
	return i;
}

//int main() {
//	const char s[6] = "Hello";
//	printf("%d\n", mx_strlen(s));
//	return 0;
//}

