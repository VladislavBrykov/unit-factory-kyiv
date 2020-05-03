#include <stdbool.h>

bool mx_is_prime(int num);

bool mx_is_prime(int num){
	for(int k = 2; k * k <= num; ++k) {
		if(num % k == 0){
	return false;
		}
	}
	return true;
}
