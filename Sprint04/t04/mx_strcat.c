#include <stdio.h>

int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) {
    int a = mx_strlen(s1);
    int b = 0;
    while((s1[a] = s2[b]) != '\0') {
        a++;
        b++;
    }
    return s1;
}

int main() {
	char s1[5] = "Hell";
	const char s2[6] = "Hello";
	printf("%s\n", mx_strcat(s1, s2));
}
