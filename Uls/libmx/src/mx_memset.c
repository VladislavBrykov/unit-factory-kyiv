#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char value = c;
    unsigned char *memory = b;
    unsigned int i = 0;

    while(i < len)
        memory[i++] = value;
    return (memory);
}

// int main () {
//    char str[40];
//    strcpy(str,"This is string.h library function");
//    puts(str);
//    mx_memset(str,'$',7);
//    puts(str);
//    return(0);
// }
