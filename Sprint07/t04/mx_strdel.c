#include <stdlib.h>

void mx_strdel(char **str) {	//new function
  if(str && *str){ 		//&& = and
    free(*str);		//ochistka pamati
    str = NULL;		//sbros na NULL
  }
}
