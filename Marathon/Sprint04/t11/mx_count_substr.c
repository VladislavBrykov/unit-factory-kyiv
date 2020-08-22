#include <string.h>

char *mx_strstr(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int n);
int mx_strlen(const char *s);
char *mx_strchr(const char*s, int c);

int mx_count_substr(const char *str, const char *sub) {

  const char *a = str;
  int file = 0;           //obiavili peremennie
  while(a != NULL) {      //poka yslovie vipolnaetsa cikl prodolzaetsa
    a = mx_strstr(a, sub);
    if(a != NULL) {
      file++;
      a++;
    }
  }
  return file;
}
