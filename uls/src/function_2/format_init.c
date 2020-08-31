#include "uls.h"

void format_init(format_t *format) {
    format->print_in_terminal = true;
    format->standart = false;
    format->long_format = false;
    format->one_per_line = false;
    format->with_commas = false;
}
