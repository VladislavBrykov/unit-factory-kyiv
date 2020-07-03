#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	char *ss1 = (char *) s1;
	char *ss2 = (char *) s2;
	size_t
	i = 0;

	while(i <= n) {
		if(ss1[i] != ss2[i])
			return(ss1[i] - ss2[i]);
		i++; 
	}
	return 0;
}

/*
int main() {
	char *str1 = mx_strnew(6);
	str1 = "Helloo";
	char *str2 = mx_strnew(6);
	str2 = "HelLoo";
printf("%d\n", mx_memcmp(str1, str2, 3));
}
*/
