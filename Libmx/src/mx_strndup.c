#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned long k = n;
    unsigned long i = 0;
    char *dst = mx_strnew(k);
    unsigned long m = mx_strlen(s1);

    if(m <= k)
    	mx_strcpy(dst, s1);
    else 
        if(m > k)
    		while(i <= k) {
    			dst[i] = s1[i];
    			i++;
    		}
    return dst;
}

/*
int main() {
    char str[] = "Hello World";
    
    printf("%s", mx_strndup(str, 2));
    return 0;
}
*/
