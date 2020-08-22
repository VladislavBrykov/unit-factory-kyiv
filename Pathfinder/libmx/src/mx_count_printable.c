#include "libmx.h"

int mx_count_printable(char *s) {
    int i = 0;
    int count = 0;

    while (s[i]) {
        if (!mx_isspace(s[i]))
            count++;
        i++;
    }
    return count;
}
