#include <stdlib.h>

char *mx_strnew(const int size) {  //obiavlaem new function
  char *peremennaia;			// obiavlaem peremennyu char
  peremennaia = (char*) malloc(size * sizeof(char) + 1); //videlaem pamat
  if (peremennaia == NULL){ //esli preemennaa = NULL, togda
    return 0;
  }
return peremennaia;
}
