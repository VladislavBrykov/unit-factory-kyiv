#include "libmx.h"

char *mx_strnew(const int size) {
    char *string = NULL;

    if (size < 0)
        return NULL;
    string = (char*)malloc(sizeof(char) * (size + 1));
    if (!string) {
        return NULL;
    }
    else {
        for (int i = 0; i < size + 1; i++) {
            string[i] = '\0';
        }
    }
    return string;
}
