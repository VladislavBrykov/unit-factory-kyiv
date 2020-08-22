#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, 
    size_t little_len) {
    const char *b = big;
    const char *l = little;

    if (big_len < little_len || !big_len || !little_len) {
        return NULL;
    }
    for (size_t i = 0; i < big_len;) {
        if (b[i] == l[0]) {
            for (size_t j = 1, k = i + 1; j < little_len 
            && b[k] == l[j]; j++, k++) {
                if (j + 1 == little_len) {
                    big = b + k - j;
                    return (void *)big;
                }
            }
        }
        i++;
    }
    return NULL;
}

/*
int main() {
	char *b = "Hello";
	char *l = "ell";
    printf("%s\n", b);
    printf("%s\n", mx_memmem(b, 6, l, 3));
}
*/
