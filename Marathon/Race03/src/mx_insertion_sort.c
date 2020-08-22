#include "header.h"

int mx_insertion_sort(char **arr, int size) {
	int res = 0;
	for (int i = 1; i < size; i++) {
		char *val = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (mx_strlen(arr[j]) > mx_strlen(arr[j + 1])) {
				arr[j + 1] = arr[j];
				res++;
			} else {
				arr[i] = val;
			}
		}
	}
	return res;
}
