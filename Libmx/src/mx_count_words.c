#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {

    int isAlpha = 0;
    int count = 0;
    
    while (*str != '\0') {
        if (isAlpha == 0 && *str != delimiter) {
            isAlpha = 1;
            count++;
        }
        if (*str == delimiter) {
            isAlpha = 0;
        }
        str++;
    }
    return  count;
}
