#include <time.h>
//#include <stdio.h>

//void mx_printable(void);

double mx_timer(void (*f)()) 
{
	double start = clock();
	f();	
	double stop = clock();
	if (start == stop) 
{
		return -1;
	}
	return (stop - start) / CLOCKS_PER_SEC;
}

//int main()
//{
//mx_timer(mx_printable);
//printf("%f", mx_timer(mx_printable));
//}
