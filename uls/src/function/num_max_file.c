#include "uls.h"

int num_max_file(char **arr) {   //ретерню номер элемента с самой большой длиной
	int i = 0;
	int j = mx_strlen(arr[0]);
	int m = 0;

	while (arr[i] != NULL) {
		if(mx_strlen(arr[i]) > j) {
			j = mx_strlen(arr[i]);
			m = i;
		}
		i++;
	}
	return (m);
}
