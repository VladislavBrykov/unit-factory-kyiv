#include <stdbool.h>

bool mx_is_prime(int num);
double mx_pow(double n, unsigned int pow);

bool mx_is_mersenne(int n) {
  if(mx_is_prime(n)) {
    int num = 1;
    unsigned int c = 1;
    while(num < n) {
      num = mx_pow(2, c) - 1;
      if(n == num)
        return true;
      c++;
      }
    }
    return false;
}
