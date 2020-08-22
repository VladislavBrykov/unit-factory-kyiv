#include "libmx.h"

static char hex_converter(int dec_digit) {
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    
    return hex[dec_digit];
}

static void hex_reverse(char *hex_nonrev) {
    char buff = 0;
    int left = 0;
    int right = mx_strlen(hex_nonrev) - 1;

    while (left < right) {
        buff = hex_nonrev[left];
        hex_nonrev[left++] = hex_nonrev[right];
        hex_nonrev[right--] = buff;
    }
}

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long result = 0;
    unsigned long out = 16;
    int i = 0;
    char *hex = mx_strnew(16);

    while (out > 0) {
        out = nbr / 16;
        result = nbr - out * 16;
        nbr = out;
        if (result < 16) 
            hex[i++] = hex_converter(result);
    }
    hex_reverse(hex);
    return hex;
}

// int main() {
//     unsigned long a;
//     a = 18446744073709551615UL;
//     //a = -1;
//     char *res = mx_nbr_to_hex(a);
//     printf("dec \"%lu\" in hex is \"%s\"\n", a, res);
//     free(res);
//     return 0;
// }
