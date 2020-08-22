#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
  int i = 0;
  int n = 0;
  int m = 1;
  if(str[i] == '-') {
    m = -1;
    i++;
  }
  while(mx_isdigit(str[i]) && !mx_isspace(str[i])) {
    n = n * 10 + str[i] - 48;
    i++;
  }
  return n * m;
}
