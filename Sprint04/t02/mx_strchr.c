#include <stdio.h>
#include <unistd.h>

char *mx_strchr(const char *s, int c) {

	char *str = (char *) s;
	while(*str){
		if(*str == (char) c)
			return str;
		str++;
	}
	if(c == '\0')
		return str;
	return 0;
}

//int main() {
//      const char s[11] = "01234567890";
//      int c = '7';
//      printf("%s", mx_strchr(s, c));
//}

