#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
	int num = 0;
	char *kesh;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (mx_strcmp(arr[i], arr[j]) > 0) {
				kesh = arr[i];
				arr[i] = arr[j];
				arr[j] = kesh;
				num++;
			}
		}
	}
	return num;
}
