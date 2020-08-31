#include "uls.h"

//сортировка, доработанный бабл сорт, ретернит имеено отсортированный массив

char **my_bubble_sort_file(char **arr, int size) {
	char *kesh;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (mx_strcmp(arr[i], arr[j]) > 0) {
				kesh = arr[i];
				arr[i] = arr[j];
				arr[j] = kesh;
			}
		}
	}
    // int num_dir = 0;  //распечатать и посмотреть на отсортированный массив массив
    //    	while(arr[num_dir]) {
    //      	printf("%s", arr[num_dir]);
    //      	printf("\t");
    //      	num_dir++;
    //    }
      return arr;
}
