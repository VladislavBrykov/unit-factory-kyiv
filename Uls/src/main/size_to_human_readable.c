#include "uls.h"

static short ost_rounder(short ost) {
    short tmp = ost;
    short pow = 1;
    short temp = 0;
    int i = 2;

    while (i-- != 0) {
      temp = tmp % 10;
      if (temp > 4)
        ost += (10 - temp) * pow;
      tmp = ost;  
      pow *= 10;
      tmp /= pow;
    }
    return ost;
}

char *size_to_readable(long long size) {
    long long tmp_size = size;
    long long ost;
    char symb[] = "BKMGTP";
    int i = 3;
    int j = 0;
    char *size_str = mx_strnew(5);

    mx_memset(size_str, ' ', 5);
    if (size < 1000) {
        if (size == 0)
            size_str[i] = '0';
        else
            while (tmp_size > 0) {
                size_str[i--] = (tmp_size % 10) + '0';
                tmp_size /= 10;
            }
        size_str[4] = symb[j];
        return size_str;
    }
    while (tmp_size > 999) {
        ost = tmp_size % 1024;
        tmp_size /= 1024;
        j++;
    }
    ost = ost_rounder(ost);
    if (ost > 999) {
        tmp_size++;
        ost = 0;
    }
    if (tmp_size == 0) {
      tmp_size++;
      ost = 0;
    }
    if (tmp_size < 10) {
        size_str[1] = tmp_size + '0';
        size_str[2] = '.';
        size_str[3] = ost / 100 + '0';
    }
    else {
        if (ost > 500) {
            tmp_size++;
            ost = 0;
        }
        while (tmp_size > 0) {
            size_str[i--] = (tmp_size % 10) + '0';
            tmp_size /= 10;
        }  
    }
    size_str[4] = symb[j];
    return size_str;
}
