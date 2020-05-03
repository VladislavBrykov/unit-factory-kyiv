//#include <stdio.h>
#include <unistd.h>

//void mx_printchar(char c);
//void mx_printint(int n);
void mx_foreach(const int *arr, int size, void (*f)(int))
{
	for (int i = 0; i < size; i++) {
		f(arr[i]);
	}
}

//int main() {
//    int arr[] = {3, 5, 7, 2, 9};
//    mx_foreach(arr, 5, mx_printint);
//}
