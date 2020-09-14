#include "uls.h"

int main(int argc, char **argv) {
    flags_t *flag = malloc(sizeof(flags_t));
    format_t *format = malloc(sizeof(format_t));
    start_t *start_data = malloc(sizeof(start_t));
    data_t ****data = malloc(sizeof(data_t***) * 3);
    largest_t ***largest = malloc(sizeof(largest_t**) * 2);

    flags_init(flag);
    format_init(format);
    input_parser(argc, argv, flag, format, start_data);
    format_detector(format, flag, start_data);
    data_collector(format, flag, start_data, data);
    largest_init(largest, start_data);
    data_sorter(format, flag, data, start_data);
    data_get_maxlen(largest, data, start_data, flag);

    if (format->long_format)
        print_long_format(data, flag, largest, start_data);
    if (format->with_commas)
        print_with_commas_format(data, flag, largest, start_data);
    if (format->one_per_line)
        print_one_per_line_format(data, flag, largest, start_data);
    if (format->standart) {
        if  (format->print_in_terminal)
            print_standart_format(data, flag, largest, start_data);
        else
            print_one_per_line_format(data, flag, largest, start_data);
    }
    if (start_data->no_fd_num > 0)
        exit(1);
    //mem_free(data, start_data);
     //system("leaks uls");
}
