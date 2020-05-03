#include <stdio.h>

int mx_factorial_rec(int n) {
	return n<=1 ? 1 : n * mx_factorial_rec(n-1);
}

//int main ()
//{
//  int n;
//  while (scanf ("%d", &n) == 1) {
//    printf ("%d\n", mx_factorial_rec(n));
//  }
//  return 0;
//}

