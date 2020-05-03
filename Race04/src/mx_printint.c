#include "./inc/header.h"

void mx_printint(long n) {
  if (n == 0) {
    mx_printchar('0');
    return;
  }
  long buf = n;
  long len = 0;
  while (n != 0) {
    n /= 10;
    len++;
  }
  n = buf;
  if (buf < 0) {
    len++;
    n *= -1;
  }
  char res[len];
  long bufl = len;
  while (n != 0) {
    res[len - 1] = (char)(n % 10 + '0');
    len--;
    n /= 10;
  }
  if (buf < 0) res[0] = '-';
  for (long i = 0; i < bufl; ++i) {
    mx_printchar(res[i]);
  }
}
