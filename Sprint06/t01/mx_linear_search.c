#include <stddef.h>

int mx_strcmp(const char *s1, const char *s2); //bydem ispolzovat fyncziy

int mx_linear_search(char **arr, const char*s){
  int i; 										//obiavlenie peremennoy

  for (i = 0; arr[i] != NULL; i++) {  //dla
    if (mx_strcmp(arr[i], s) == 0) { //esli
      return i;
    }
  }
  return -1;
}
