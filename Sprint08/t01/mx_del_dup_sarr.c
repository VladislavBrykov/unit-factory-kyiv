#include "duplicate.h"

int *mx_del_dup_arr(int *src, int src_size, int *dst_size){
	if (*src == 0)
		return NULL;
	
	int size = 0;
	int t = 0;
	int arr[src_size];

	for(int i = 0; i < src_size; i++){
		for(int j = 0; j < size; j++){
			if(arr[j] == src[i]){
				t = 1;
			}
		}

		if(t == 1){
			t = 0;
		}
		else {
			arr[size] = src[i];
			size++;
		}
	}
	
	*dst_size = size;
	int *p;
	p = mx_copy_int_arr(arr, size);

	return p;
}

int main()
{
	int src[] = { 5, 3, 3, 2, 1 };
	int dst_size[6];
	printf("%d\n", *mx_del_dup_arr(src, 5, dst_size));
	return 0;
}

