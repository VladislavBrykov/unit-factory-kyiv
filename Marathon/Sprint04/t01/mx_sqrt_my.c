#include <stdio.h>

int mx_sqrt(int x) {
	int i = 0;
	if (i < 0)
		return 0;
	while(i < x) {
		if((i * i) == x)
			return i;
		else 
			i++;
		}
	return 0;
}

int main() {
	printf("%d\n", mx_sqrt(11));
	return 0;
}
