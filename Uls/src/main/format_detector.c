#include "uls.h"

void format_detector(format_t *format, flags_t *flag, start_t *start_data) {
    if (isatty(1) != 1)
        format->print_in_terminal = false;
    if (flag->h)
        format->human_readable = true;
    if (flag->r)
        format->sorting.revesre = true;
    if (flag->S)
        format->sorting.size = true;
    else if(flag->t)
            format->sorting.time = true;
        else 
            format->sorting.standart = true; 

    if (flag->l || flag->n || flag->g || flag->o) {
        format->long_format = true;
        return;
    }
    if (flag->m) {
        format->with_commas = true;
        return;
    }
    if (flag->one) {
        format->one_per_line = true;
        return;
    }
    format->standart = true;
}
