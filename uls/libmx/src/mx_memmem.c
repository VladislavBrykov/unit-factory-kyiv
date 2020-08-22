#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const unsigned char *b = big;
    const unsigned char *l = little;
    
    if(big_len <= 0 || little_len <= 0 || big_len < little_len) 
        return NULL;
    for (unsigned int i = 0, j = 0, flag = 1; i < big_len; i++, j = 0, flag = 1)
        if (b[i] == l[j]) {
            while ((++j) < little_len) { 
                if (l[j] != b[i + j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) 
                return (void*)(b + i);
        }
    return NULL;
}

// int main() {
//     void *result = NULL; 
//     char a[10] = "hello";
//     char b[3] = "he";
//     result = mx_memmem(a, 5, b, 2);
// }
