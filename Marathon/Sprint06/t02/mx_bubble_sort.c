#include <stdio.h>
#include <unistd.h>

int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;
	while(s1[i]) {
		if(s1[i] != s2[i])
			return(s1[i] - s2[i]);
		if(s1[i] == s2[i])
			i++;
		}
	return 0;
}

int mx_bubble_sort(char **arr, int size) {
	char *string;
	int number = 0;
	for(int i = 0; i < size; i++) {
		for(int j = i+1; j < size; j++) {
			if(mx_strcmp(arr[i], arr[j]) > 0) {
				string = arr[i];
				arr[i] = arr[j];
				arr[j] = string; 
				number++;	
				}
			}
		}
		return number;
}

int main() {
	char *arr[4] = {"abc", "xyz", "ghi", "def"};
	printf("%d\n", mx_bubble_sort(arr, 4));
	char *arr1[3] = {"abc", "acb", "a"};
	printf("%d\n", mx_bubble_sort(arr1, 3));
}			
