#include "pathfinder.h"

int my_atoull(const char *string) {
	unsigned long long num = 0;
	int index = 0;

	for ( ; string[index]; index++)
		if (mx_isdigit(string[index])) {
			num = (num * 10) + (string[index] - '0');
		}
		else
			break;
	if (num > 2147483647)
		return (int)-1;
	return (int)num;
}
