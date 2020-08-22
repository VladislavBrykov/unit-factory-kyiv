#include <stdio.h>

void mx_printstr(const char *s);

void mx_is_positive(int i) {
	if (i > 0)
		mx_printstr("positive\n");
	else if (i < 0)
		mx_printstr("negative\n");
	else
		mx_printstr("zero\n");
}

//int main()
//{
//	mx_is_positive(6);
//	return 0;
//}
