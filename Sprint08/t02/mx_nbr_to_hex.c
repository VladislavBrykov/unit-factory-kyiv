nclude "nbr_to_hex.h"
char *mx_nbr_to_hex(unsigned long nbr) {
        char hexa[10];
        int i = 0;
        int num = nbr;
        while(num != 0) {
                int temp = 0;
        temp = num % 16;
        if (temp < 10) {
                hexa[i] = temp + 48;
                i++; }
        else {
                hexa[i] = temp + 55;
                i++; }
        num /= 16; }
        char *arr = mx_strnew(i);
        for(int a = i - 1, index = 0; a >= 0; a--, index++) {
                arr[index] = hexa[a]; }
        return arr;
}
