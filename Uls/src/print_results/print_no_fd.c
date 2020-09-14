#include "uls.h"

void print_no_fd(start_t *start_data) {
    for (int i = 0; i < start_data->no_fd_num; i++) {
        mx_printerr("uls: ");
        mx_printerr(start_data->no_file_dir[i]);
        mx_printerr(": No such file or directory\n");
    }
}
