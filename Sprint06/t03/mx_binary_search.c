int mx_strcmp( const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count){
  int firstEl = 0;  //obiavlenie peremennih
  int lastEl = size - 1; //obiavlenie peremennih
  int middleEl; //obiavlenie peremennih

  if(!*arr) {  // yslovie esli
    return -1; //togda
  } else { //inache
    while (firstEl <= lastEl) {  //zapuskaem cikl while
      (*count)++;
      middleEl = (firstEl + lastEl) / 2;
      if (mx_strcmp(arr[middleEl], s) > 0) {
	lastEl = middleEl - 1;
      }else if (mx_strcmp(arr[middleEl], s) == 0) { //inache esli
	return middleEl;  //rezultat
      } else {
	firstEl = middleEl + 1;
      }
    }
    *count = 0;
    return -1;
  }  
}
