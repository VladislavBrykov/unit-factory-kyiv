#include "pathfinder.h"

static void error(void) {
    mx_printerr("error: line 1 is not valid\n");
    free(in_data.string);
    exit(1);
}

void invalid_first_line(void) {
    int i = 0;
    int num_atoul = my_atoull(in_data.string);

    if (!(mx_isdigit(in_data.string[i])) || num_atoul < 0)
        error();
    while (in_data.string[i] != '\n') {
        if (!(mx_isdigit(in_data.string[i])) || num_atoul < 0)    // only check if < 0 values and is digit
            error();
        i++;
    }
    in_data.num_of_islands = num_atoul;
}
