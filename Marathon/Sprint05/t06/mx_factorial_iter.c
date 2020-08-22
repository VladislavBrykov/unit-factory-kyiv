#include <stdio.h>

int mx_factorial_iter(int n) {
	if (n < 0)
		return 1;
	int fact = 1;
	for(int i = 1; i <= n; i++)
		fact = fact * i;
	if(fact <= 214783647)
		return fact;
	//	printf("%d", fact);
	else if(fact > 2147473647)
		return 0;
	return 0;
}

//int main()
//{
//	mx_factorial_iter(5);
//	return 0;
//}
