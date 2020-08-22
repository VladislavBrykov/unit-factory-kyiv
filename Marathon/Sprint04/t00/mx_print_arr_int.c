#include <unistd.h>
#include <stdio.h>

void mx_printchar(char c)
{
	write(1, &c, 1);
}

void mx_printint(int n) {
long num = n;
if (num < 0) {
    mx_printchar('-');
    num *= -1;
}
if (num > 9)
    mx_printint(num / 10); //recursion
mx_printchar(num % 10 + 48);
}

void mx_print_arr_int(const int *arr, int size) {
	for(int i = 0; i < size; i++) {	
		mx_printint(arr[i]);
		mx_printchar('\n');
	}
}

//int main()
//{
//	int array[5] = { 1, 2, 3, 4, 5 };
//	mx_print_arr_int(array, 5);
//	return 0;
//}
