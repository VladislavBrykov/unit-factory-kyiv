#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    char *result;
    
    if (size < 1 && ptr != 0) {
        free(ptr);
        return malloc(1);
    }
    if (ptr == NULL)
        return malloc(size);
    if (!(result = malloc(size)))
        return NULL;
    mx_memcpy(result, ptr, size);
    free(ptr);
    return (void*)result;
}

// int main() {
//     int size = 150;
//     char *string = malloc(12);
//     char *b = "Hello world";
//     mx_memcpy(string, b, 12);
//     string = mx_realloc(string, size);
//     for(int i = 0; i < size; i++)
//         printf("%c", string[i]);
//     printf("\n");
//     free(string);
// }
