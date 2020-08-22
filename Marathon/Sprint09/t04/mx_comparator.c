#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int mx_comparator(const int *arr, int size, int x, bool (*compare)(int, int)) {
for(int i = 0; i < size; i++) {
	if(compare(arr[i], x))
		return i;
	}
	return -1;
}

/*
bool equal_nums(int a, int b) {
return a == b;
}

В задании сказано сдать всего одну функцию, поэтому bool комментируем.
*/


int main() {
	int arr[] = {1, 2, 3, 4, 5};
	printf("%d\n", mx_comparator(arr, 5, 2, equal_nums));
	return 0;
}

/*bool (*compare)(int, int) - указатель на функцию, говорит, подставь функцию.
*compare указатель на функцию equal_nums 
мы по сути подставляем функцию bool equal_nums(int a, int b)

DESCRIPTION
In this task, follow the directions below:
• create a function that searches the integer x in the array arr given size
• searching criteria must be defined in bool (*compare)(int, int) passed as a function
pointer parameter, in which the first parameter is the array element and the second
is x
RETURN
• returns the index of the first element in the array matching true criteria of the
compare function
• returns -1 in case of errors or if x has not been found
SYNOPSIS
int mx_comparator(const int *arr, int size, int x, bool (*compare)(int, int));
EXAMPLE
bool equal_nums(int a, int b) {
return a == b;
}

arr = {1, 2, 3, 4, 5};
mx_comparator(arr, 5, 3, equal_nums); //returns 2
mx_comparator(arr, 5, -1, equal_nums); //returns -1
*/
