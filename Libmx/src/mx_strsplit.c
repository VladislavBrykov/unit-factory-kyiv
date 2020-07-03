#include "libmx.h"

char **mx_strsplit(char const *s, char c) {
    int massiv = mx_count_words(s, c);
    char **result = (char **) malloc(sizeof(char *) * (massiv + 1)); //videlaem pamat
    result[massiv] = 0;

    if (s == 0)
        return 0;
    for (int p = 0; p < massiv; p++) {
        while (*s == c) {
            s++;
        }
        char *peremennaia = (char *) s;
        int dlina = 0;
        while (*s != c) {
            dlina++;
            s++;
        }
        char *word = mx_strnew(dlina);
        mx_strncpy(word, peremennaia, dlina);
        result[p] = word;
    }
    return result;
}
