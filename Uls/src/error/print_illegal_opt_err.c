#include "uls.h"

void err_ill_option(char c, flags_t *flag) {
    mx_printerr("ls: illegal option -- ");
    write(2, &c, 1);
    mx_printerr("\nusage: ls [-");
    mx_printerr(flag->all_flags);
    mx_printerr("] [file ...]\n");
    exit(1);
}
