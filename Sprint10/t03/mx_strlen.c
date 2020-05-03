#include "file_to_str.h"

int mx_strlen(const char *s){
  int i;
  int j = 0;

  for (i = 0; s[i] != '\0'; i++){
    if (s[i] == j) {
      return j++;
    }
  }
  return i;
}
