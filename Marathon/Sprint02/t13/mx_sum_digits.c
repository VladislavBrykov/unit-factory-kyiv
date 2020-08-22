#include <stdio.h>

int mx_sum_digits(int num) {

	int sum = 0;
	if (num < 0)
		num = (num * -1);
	while(num != 0) {
		sum = sum + num % 10;
		num = num / 10;
	}				
	return sum;
}

//int main()
//{
//	mx_sum_digits(-6666);
//	return 0;
//}

