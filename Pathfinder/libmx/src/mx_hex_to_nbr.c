#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = mx_strlen(hex);
    unsigned long base = 1;
    unsigned long dec = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
        }
        else
            return 0;
        base *= 16;
    }
    return dec;
}
