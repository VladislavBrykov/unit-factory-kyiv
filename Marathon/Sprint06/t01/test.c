#include <stdio.h>

int c = 0;
int min;
char *tmp;

for (int i = 0; i < size - 1; i++) {
	min = i;
	for(int j = i + 1; j < size; j++)
		if((strlen(arr[j] < strlen(arr[min])))) || (strlen(arr[j]) - strlen(arr[min]) == 0) && strcmp(arr[j], arr[min]) < 0))
} 

int main(void) {
	char *arr[] = {"Abcd", "a", "aBc", "abc", "Z", "z", "AbCd"};
	//char *arr[] = {"Z", "Abcd", "a", "aBc", "z", "abc", "AbCd"};
	printf("%d\n", mx_selection_sort(arr, 7));
	//5
	//4
}
