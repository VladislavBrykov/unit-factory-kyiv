void mx_sort_arr_int(int *arr, int size {
  int i;
  int j;
  int t;
  for(i = 0; i < size-1; i++) {
    for(j = 0; j < size-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        t = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = t;
      }
    }
  }
}
