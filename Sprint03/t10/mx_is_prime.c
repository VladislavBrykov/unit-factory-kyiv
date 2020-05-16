#include <stdbool.h>

bool mx_is_prime(int num) {
	if (num > 1)
	{
	for(int k = 2; k < num; ++k)
		if(num % k == 0) {
			return false;
		}
		return true;
	}
	else 
		return false;
	
}

int main()
{
	mx_is_prime(2);
	return 0;
}
