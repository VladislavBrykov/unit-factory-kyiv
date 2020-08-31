#include "uls.h"

void format_detector(format_t *format, flags_t *flag, start_t *start_data) {
    if (isatty(1) != 1)
        format->print_in_terminal = false;
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
