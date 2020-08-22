#include "pathfinder.h"

static void printerror(void) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        free(in_data.string);
        free(in_data.uniqe_islands);
        exit(1);
}

void invalid_sum_of_bridges(void) {
    int i = 0;
    unsigned long sum = 0;
    bool bor_res = true;
    int res;

    while (1) {
        for ( ; in_data.string[i] != ','; i++) 
            if (in_data.string[i] == '\0') {
                bor_res = false;
                break;
            }
        if (bor_res) {
            res = my_atoull(&in_data.string[++i]);
            if (res == -1)
                printerror();
            sum += res;
            i++;
        }
        else 
            break;
    }
    if (sum > INT_MAX)
        printerror();
}
