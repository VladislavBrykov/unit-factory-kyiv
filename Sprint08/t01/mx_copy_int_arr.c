#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    if (src == 0 || size <= 0) {
        return 0;
    }
    int *dst = malloc(sizeof(int) * size);
    if (dst == 0) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        dst[i] = src[i];
    }
    return dst;
}
