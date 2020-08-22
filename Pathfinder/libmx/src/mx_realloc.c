#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    char *pptr = (char *)ptr;
    size_t len = mx_strlen(pptr);
    char *result;

    if (size == 0 && pptr) {
        free(pptr);
            return NULL;
    }
    if (size && !pptr) {
        return malloc(size);
    }
    if (len > size) {
        result = malloc(len);
        if (!result) return NULL;
            result = mx_memmove(result, pptr, len);
    } 
    else {
        result = malloc(size);
        if (!result) 
            return NULL;
        result = mx_memmove(result, pptr, size);
    }
    return (void *)result;
}

/*
int main() {
    char ptr[] = "elloooo";
    mx_realloc(ptr, 44);
    printf("%s\n", ptr);
    return 0;
} 
*/
