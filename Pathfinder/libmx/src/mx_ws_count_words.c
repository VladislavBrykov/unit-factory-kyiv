#include "libmx.h" 

int mx_ws_count_words(char *s) {
    int i = 0;
    int count = 0;

    while (s[i]) {
        if (!mx_isspace(s[i]) && mx_isspace(s[i + 1]))
            count++;
        i++;
    }
    return ++count;
}
