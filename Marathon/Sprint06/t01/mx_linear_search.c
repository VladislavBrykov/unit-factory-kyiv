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
		

int mx_linear_search(char **arr, const char*s){
  	int i;
  	for (i = 0; arr[i] != NULL; i++) {
    		if (mx_strcmp(arr[i], s) == 0) {
      			return i;
    			}
  		}
  	return -1;
}

int main() {
	char *arr[7] = {"222", "Abcd", "aBc", "ab", "az", "z", NULL};
	printf("%d\n", mx_linear_search(arr, "z"));
}
