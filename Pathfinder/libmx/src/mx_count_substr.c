#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {

  const char *a = str;
  int file = 0;
  
  while(a != NULL) {
    a = mx_strstr(a, sub);
    if(a != NULL) {
      file++;
      a++;
    }
  }
  return file;
}
