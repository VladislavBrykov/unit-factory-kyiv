#include "header.h"

int mx_strlen(const char *s)
{
	int i = 0;
	while(s[i]) {
		i++;
	}
	return i;
}

/*int main()
{
	printf("%d\n", mx_strlen("fghj"));
	return 0;
}*/
