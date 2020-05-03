int mx_strcmp( const char *s1, const char *s2);  //bydem ispolzovat

int mx_bubble_sort(char **arr, int size) { //obiavlaem novyy fynkziy
  int swap = 0;
  char *temp;
  int i, j;

  for (i = 0; i < size; i++) {  //dla
    for (j = i; j < size; j++) {  //dla
      if (mx_strcmp(arr[i], arr[j]) > 0) { //esli
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	swap++;
      }
    }
  }
  return swap;
}
