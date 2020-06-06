#include <unistd.h>
#include <stdio.h>

void mx_foreach(const int *arr, int size, void (*f)(int)) {
	for(int i = 0; i < size; i++) {
		f(arr[i]);
	}
}

/*void mx_printchar(char c)
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

int main() {
	int arr[] = {1, 2, 3, 4, 5};
mx_foreach(arr, 5, mx_printint); //prints "12345" to the standart output
}

Убираем все функции поскольку в задании сказано сдать только одну функцию/

DESCRIPTION
Create a function that applies the function f for each element of the array arr given
size .
SYNOPSIS
void mx_foreach(const int *arr, int size, void (*f)(int));
EXAMPLE
void mx_printint(int n);
arr = {1, 2, 3, 4, 5};
mx_foreach(arr, 5, mx_printint); //prints "12345" to the standart output
*/

