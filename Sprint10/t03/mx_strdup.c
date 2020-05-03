#include "file_to_str.h"

char *mx_strdup(const char *str) {
    int length = mx_strlen(str);
    char *result = mx_strnew(length);
    mx_strcpy(result, str);
    return result;
}
