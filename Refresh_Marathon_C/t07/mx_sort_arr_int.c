void mx_sort_arr_int(int *arr, int size) {
	int num = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i -1; j++) {
			if (arr[j] > arr[j + 1]) {
				num = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = num;
			}
		}
	}
}
