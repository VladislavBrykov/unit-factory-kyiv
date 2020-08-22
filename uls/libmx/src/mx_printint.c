#include "libmx.h"

void mx_printint(int n) {
	long number = n;

	if (number < 0) {
		mx_printchar('-');
		number *= -1;
	}
	if (number > 9) 
		mx_printint(number / 10);
	mx_printchar(number % 10 + 48);
}
