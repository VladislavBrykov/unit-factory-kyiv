#include <stdbool.h>
#include <stdio.h>


bool mx_is_odd(int value) 
{
	return (value % 2 != 0);
}

int main()
{
	mx_is_odd(4);
}
