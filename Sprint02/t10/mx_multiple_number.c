#include <stdio.h>
#include <stdbool.h>

bool mx_multiple_number(int n, int mult) {
	if (n * n == mult)			
		printf("%d", 2);			
	else
		printf("%d", 1);
	return 0;
}

int main()
{
	mx_multiple_number(0, 1);
}

