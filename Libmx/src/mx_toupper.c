#include "libmx.h"

int mx_toupper(int c) {
        if (c>96 && c<123) {
        c -= 32;
	}       
        return c;
} 

//int main()
//{
//	printf("%c",mx_toupper('z'));
//}
