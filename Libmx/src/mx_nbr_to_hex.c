#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long nbr2 = nbr;
    int lenght = 1;
    int temp;
    int i = 0;
  
    while((nbr2 / 10) > 1) {
        nbr2 /= 10;
        lenght++;
    }
    char *string = mx_strnew(lenght);
      while(nbr != 0) {
          temp = nbr % 16;
          if(temp < 10) {
              string[i] = 48 + temp;
          }
          else {
              string[i] = 87 + temp;
          }
      nbr /= 16;
      i++;
      }
  mx_str_reverse(string);
  return string;
}

/*
int main(void) {
  unsigned long temp = 10000;
  char *a = mx_nbr_to_hex(temp);
  printf("%s", a);
}
*/
