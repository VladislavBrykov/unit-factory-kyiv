#include <stdbool.h>

bool mx_multiple_number(int n, int mult)
{
	return(mult % n == 0);
}

int main()
{
	mx_multiple_number(3, 9);
	return 0;
}
