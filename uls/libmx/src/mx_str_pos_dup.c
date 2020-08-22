#include "libmx.h"

char *mx_str_pos_dup(char *src, int start, int finish) {    
    char *dst = mx_strnew(finish - start + 1);

    for (int i = 0; i <= finish - start; i++)
        dst[i] = src[start + i];
    return dst;
}
