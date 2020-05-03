//#include <stdio.h>

void mx_printchar(char c);

void mx_isos_triangle(unsigned int length, char c)
{
	for(unsigned int i = 0; i<length; i++) {	//1 cikl - stolbci
		for(unsigned int j = 0; j <= i; j++)  //2 cikl ctroki
		mx_printchar(c);
		mx_printchar('\n');
	}
}

//int main()
//{
//	mx_triangle(3, '*');
//	return 0;
//}
