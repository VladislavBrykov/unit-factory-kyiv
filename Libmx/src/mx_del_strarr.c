#include "libmx.h"

void mx_del_strarr(char ***arr) {
    for (int b = 0; (*arr)[b]; b++) {
        free((*arr)[b]);
    }
    free(*arr);
    *arr = NULL;
}
