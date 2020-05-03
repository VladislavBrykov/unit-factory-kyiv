#include <stdbool.h>

bool mx_islower(int c);
bool mx_isupper(int c);
bool mx_tolower(int c);
bool mx_toupper(int c);

void mx_reverse_case(char *s) {	//new function
	int c = 0;					//obiavlaem peremennyu
	while (s[c]) {				//cicl while, poka vipilnaetsa yskovie
		if (mx_islower(s[c]))
	s[c] = mx_toupper(s[c]);
		else if (mx_toupper(s[c]))
	s[c] = mx_tolower(s[c]);
		c++;
	}
}
