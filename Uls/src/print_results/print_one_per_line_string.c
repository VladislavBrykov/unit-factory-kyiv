#include "uls.h"

static char *field_maker(int size) {
    char *str = mx_strnew(size);
    mx_memset(str, ' ', size);
    return str;
}

static char *field_filler(char *field, char *data, int size, bool right_side) {
    int start = 0;

    if (right_side)
        start = size - mx_strlen(data);
    for (int i = 0; data[i] != '\0'; i++)
        field[start++] = data[i];  
    return field;
}

static void field_printer(char *field, short spaces_after) {
    mx_printstr(field);
    for (int i = 0; i < spaces_after; i++)
        mx_printchar(' ');
}

static void print_processor(short len, char *data_field, short spaces_after, bool right_side) {
    char *field = field_maker(len);
    field = field_filler(field, data_field, len, right_side);
    field_printer(field, spaces_after);
    free(field);
}

void print_one_per_line_string(data_t **data, flags_t *flag, largest_t *largest) {

    for (int i = 0; data[i] != NULL; i++) {
        if (flag->i)
            print_processor(largest->indnumlen, data[i]->ind_num_ch, 1, true);
        if (flag->s)
            print_processor(largest->bloknumlen, data[i]->block_ch, 1, true);
        mx_printstr(data[i]->name);
        mx_printstr("\n");
        if (flag->F)
            switch (data[i]->type) {
                case 'd': mx_printchar('/'); break;
                case 'l': mx_printchar('@'); break;
                case '-': if (data[i]->rights[2] == 'x') mx_printchar('*'); break;
            }
        if (data[i + 1] != NULL)
            mx_printchar('\n');
    }
}
