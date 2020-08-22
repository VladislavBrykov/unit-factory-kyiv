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

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int first = 0;
	int last = size - 1;
	int middle;
	while(first <= last) {
		middle = (first + last) / 2;
			if(mx_strcmp(arr[middle], s) > 0) {
				last = middle - 1;
				(*count)++;
			}
			else if(mx_strcmp(arr[middle], s) < 0) { 
				(*count)++;
				first = middle + 1;
			}
			else {
				(*count)++;
				return middle;
			}	
	}
	count = 0;
	return -1;
}

int main() {
char *arr[6] = {"222", "Abcd", "aBc", "ab", "az", "z"};
int count = 0;
printf("%d\n", mx_binary_search(arr, 6,"ab", &count));
printf("%d\n", count);
}	
