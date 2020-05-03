#include "./inc/header.h"

int mx_atoi(const char *str) {
  int i = 0;
  int s = 0;
  int n = 0;

  while (mx_isspace(str[i])) {
    i++;
  }
  if (str[i] == '-' && mx_isdigit(str[i + 1]) == 1) {
    s = 1;
  }
  if ((str[i] == '-' || str[i] == '+') && mx_isdigit(str[i + 1]) == 1) {
    i++;
  }
  while (mx_isdigit(str[i])) {
    n = n * 10 + (str[i] - 48);
    i++;
  }
  if (s == 1) {
    return -n;
  }
  return n;
}
