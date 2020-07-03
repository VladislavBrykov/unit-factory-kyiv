#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
  int k = 0;
  int t = 0;

    for(int i = 0; str[i]!='\0'; i++) {
      if(str[i] == sub[0]) {
        t = i;
      while(sub[k] != '\0') {
        if(str[t] == sub[k]) {
          k++;
          t++;
        }
        else {
          k--;
          break;
        }
      }
    if(k == mx_strlen(sub))
      return i;
      }
    }
    return -1;
}

/*
int main() {
  char first[] = "Heello";
  char second[] = "el";
  printf("%d\n", mx_get_substr_index(first, second));
}
*/
