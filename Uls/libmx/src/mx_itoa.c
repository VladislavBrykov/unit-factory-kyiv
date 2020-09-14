#include "libmx.h"

static int mx_intlen(int num) {
    int len = 1;

    while (num /= 10)
        len++;
    return len;
}

char *mx_itoa(int number) {
    char *result = mx_strnew(12);
    if (number == -2147483648)
        result = mx_strcpy(result, "-2147483648");
    else if (number == 0)
            result = mx_strcpy(result, "0");
        else {
            int num_len = mx_intlen(number);
            if (number < 0) {
                result[0] = '-';
                number *= -1;
                num_len++;
            }
            result[num_len] = '\0';
            while (number) {
                result[--num_len] = (char) ((number % 10) + 48);
                number /= 10;
            }
        }
    return result;
}
