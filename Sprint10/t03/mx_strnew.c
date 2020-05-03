#include "file_to_str.h"

char *mx_strnew(const int size){
  char *i;
  i = (char*) malloc(size * sizeof(char) + 1);
  if (i == NULL){
    return 0;
  }
return i;
}
